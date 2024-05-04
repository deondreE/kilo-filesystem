import Foundation
import SwiftUI

struct ContentView: View {
  var body: some View {
    HStack {
      SidebarView()
      Text("Hello General Content")
    } 
  }
}

#Preview {
  ContentView()
}