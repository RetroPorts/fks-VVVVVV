#ifndef SCREEN_H
#define SCREEN_H

#include <SDL.h>

enum class ScaleMode
{
  CROPPED, ASPECT, STRETCHED
};


class Screen
{
private:
  void scale_NN_AllowOutOfScreen(SDL_Surface *src_surface, SDL_Surface *dst_surface, int new_w, int new_h);

  ScaleMode mode;

public:
	Screen();

	void ResizeScreen(int x, int y);
	void GetWindowSize(int* x, int* y);

	void UpdateScreen(SDL_Surface* buffer, SDL_Rect* rect);
	void ClearScreen(int colour);
	void FlipScreen();

	const SDL_PixelFormat* GetFormat();

	void toggleFullScreen();
	void toggleStretchMode();
	void toggleLinearFilter();

  void nextScaleMode();

	bool isWindowed;
	bool isFiltered;
	bool badSignalEffect;
	bool glScreen;
	int stretchMode;

  SDL_Surface* hw_screen;
	SDL_Surface* m_screen;

	SDL_Rect filterSubrect;
};



#endif /* SCREEN_H */
