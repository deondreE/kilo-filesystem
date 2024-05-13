// for the linux version only.

#pragma once

#ifdef KPLATFORMLINUX
  #include <X11/Xlib.h>
  #include <core.h>

  typedef struct {
    Display *display;
    Window window;
  } WindowManager; 

  void createWindow(WindowManager *wm) 
  {
    wm->display = XOpenDisplay(NULL);
    if (wm->display == NULL) {
      fprintf(stderr, "Cannot Open Display!");
      return;
    }

    int screen = DefaultScreen(wm->display);
    wm->window = XCreateSimpleWindow(wm->display, RootWindow(wm->display, screen), 
                                     100, 100, 400, 300, 1,
                                     BlackPixel(wm->display, screen),
                                     WhitePixel(wm->display, screen));

    XSelectInput(wm->display, wm->window, ExposureMask | KeyPressMask);

    XMapWindow(wm->display, wm->window);
  }


  void handleEvents(WindowManager *wm) 
  {
    XEvent event;
    while (1) 
    {
      XNextEvent(wm->display, &event);
      if (event.type == Expose) {
        // Hamdle expose event
      } 
      if (event.type == KeyPress) 
        break;
    }
  }

  void cleanup(WindowManager *wm) 
  {
    XDestroyWindow(wm->display, wm->window); 
    XCloseDisplay(wm->display);
  }  
#endif