#pragma once
#include <pugixml/pugixml.hpp>

namespace {
	/**
	 * @brief this abstract class acts an interface that enables xml based serialization.
			  this method is supposed to recursively generate an xml_document that can be used
			  inside a larger node tree.
			  implement in classes where xml serialization is needed, then during serialzation, this
			  function can be called for serializing that class.
	*/
	class XmlSerializable {
	public:
		virtual pugi::xml_document* serializeToXml()=0;
	};
}