#pragma once

namespace meteor {
	/**
	 * @brief RenderLayers aid the Rendering system to 
	 * batch render commands. the order of render is as follows
	 * World -> UI -> Debug.
	*/
	enum RenderLayer {
		World,
		UI,
		Debug
	};
}