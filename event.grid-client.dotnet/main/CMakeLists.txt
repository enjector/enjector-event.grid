project(event.grid-client.dotnet CSharp)

set(SOURCE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(SOURCE_FILES
    ${SOURCE_PATH}/NodeClient.cs
)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES VS_DOTNET_TARGET_FRAMEWORK_VERSION "v4.7.2")
#set_property(TARGET Example PROPERTY VS_DOTNET_REFERENCES
#    "Microsoft.CSharp"
#    "PresentationCore"
#    "PresentationFramework"
#    "System"
#    "System.Core"
#    "System.Data"
#    "System.Data.DataSetExtensions"
#    "System.Net.Http"
#    "System.Xaml"
#    "System.Xml"
#    "System.Xml.Linq"
#    "WindowsBase")

set_target_properties(${PROJECT_NAME} PROPERTIES VS_PACKAGE_REFERENCES
    "BouncyCastle_1.8.5"
)

set_property(TARGET ${PROJECT_NAME}
    PROPERTY VS_PACKAGE_REFERENCES
       "BouncyCastle_1.8.5"
)