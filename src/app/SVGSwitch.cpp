#include "app/SVGSwitch.hpp"


namespace rack {


SVGSwitch::SVGSwitch() {
	sw = new SVGWidget;
	addChild(sw);
}

void SVGSwitch::step() {
	ParamWidget::step();
	FramebufferWidget::step();
}

void SVGSwitch::addFrame(std::shared_ptr<SVG> svg) {
	frames.push_back(svg);
	// If this is our first frame, automatically set SVG and size
	if (!sw->svg) {
		sw->setSVG(svg);
		box.size = sw->box.size;
	}
}

void SVGSwitch::onChange(const event::Change &e) {
	assert(frames.size() > 0);
	if (paramQuantity) {
		int index = paramQuantity->getScaledValue() * (frames.size() - 1);
		index = math::clamp(index, 0, (int) frames.size() - 1);
		sw->setSVG(frames[index]);
		dirty = true;
	}
	ParamWidget::onChange(e);
}


} // namespace rack
