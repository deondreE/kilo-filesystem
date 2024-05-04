import Foundation
import SwiftUI

func start_process( ) {
  guard let url = URL(string: "/Users/deondreenglish/Projects/OpenSource/kilo-filesystem/scripts/run.sh") else { return }
  do {
    try Process.run(url, arguments: [""])
  } catch {
    Process().terminate()
    print("ERR")
  }
}

struct ContentView: View {
  var body: some View {
    HStack {
      SidebarView()
      Text("Hello General Content")
      
      let _ = {
        start_process()
      }()
    }
  }
}

#Preview {
  ContentView()
}
