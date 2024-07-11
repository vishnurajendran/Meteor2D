#pragma once
#include <rendering/rendercommand.h>
#include <meteorutils/suirect.h>

namespace meteor {
	class MUIRenderCommand : public MRenderCommand {

	public:
		MUIRenderCommand(int layerOrder);
		void setAbsoluteUIRect(SUIRect absRect);
		void render() override;
	};
}