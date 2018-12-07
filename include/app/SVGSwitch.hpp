#pragma once
#include "app/common.hpp"


namespace rack {


/** A ParamWidget with multiple frames corresponding to its value */
struct SVGSwitch : virtual ParamWidget, FramebufferWidget {
	std::vector<std::shared_ptr<SVG>> frames;
	SVGWidget *sw;

	SVGSwitch();
	/** Adds an SVG file to represent the next switch position */
	void addFrame(std::shared_ptr<SVG> svg);
	void onChange(event::Change &e) override;
};


} // namespace rack