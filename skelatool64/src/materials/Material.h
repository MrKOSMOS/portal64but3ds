#ifndef _MATERIAL_H
#define _MATERIAL_H

#include <string>
#include <vector>
#include <memory>
#include <map>
#include <ostream>

#include "TextureDefinition.h"
#include "../DisplayList.h"
#include "../ExtendedMesh.h"
#include "MaterialState.h"
#include "../definitions/DataChunk.h"
#include "../CFileDefinition.h"

#include "MaterialEnums.h"

enum class NormalSource {
    Normal,
    Tangent,
    MinusTangent,
    Bitangent,
    MinusCotangent,
};

class Material {
public:
    Material(const std::string& name);
    std::string mName;
    MaterialState mState;
    std::map<std::string, std::string> mProperties;
    NormalSource mNormalSource;
    bool mExcludeFromOutut;

    void Write(CFileDefinition& fileDef, const MaterialState& from, StructureDataChunk& output, bool targetCIBuffer);

    static int TextureWidth(Material* material);
    static int TextureHeight(Material* material);

    static VertexType GetVertexType(Material* material);
};

#endif