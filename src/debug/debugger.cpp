// Copyright (c) 2024 dudubles

// Title  : debugger.cpp
// Author : @Dudubles
// Date   : 07/19/24

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <bware/debug/debugger.hpp>
#include <glad/glad.h>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

namespace debugger {

void InitializeDebugTools(GLFWwindow *window) {
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO &io = ImGui::GetIO();
  (void)io;
  SetupBrainwareStyle();
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 460");
}

void StartFrame() {
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();
}

void EndFrame() {
  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void SetupBrainwareStyle() {
  ImGuiStyle &style = ImGui::GetStyle();

  style.Alpha = 1.0f;
  style.DisabledAlpha = 0.6000000238418579f;
  style.WindowPadding = ImVec2(8.0f, 8.0f);
  style.WindowRounding = 13.0f;
  style.WindowBorderSize = 1.0f;
  style.WindowMinSize = ImVec2(32.0f, 32.0f);
  style.WindowTitleAlign = ImVec2(0.0f, 0.5f);
  style.WindowMenuButtonPosition = ImGuiDir_Left;
  style.ChildRounding = 0.0f;
  style.ChildBorderSize = 1.0f;
  style.PopupRounding = 0.0f;
  style.PopupBorderSize = 1.0f;
  style.FramePadding = ImVec2(4.0f, 3.0f);
  style.FrameRounding = 16.5f;
  style.FrameBorderSize = 2.0f;
  style.ItemSpacing = ImVec2(8.0f, 4.0f);
  style.ItemInnerSpacing = ImVec2(4.0f, 4.0f);
  style.CellPadding = ImVec2(4.0f, 2.0f);
  style.IndentSpacing = 21.0f;
  style.ColumnsMinSpacing = 6.0f;
  style.ScrollbarSize = 14.0f;
  style.ScrollbarRounding = 9.0f;
  style.GrabMinSize = 10.0f;
  style.GrabRounding = 0.0f;
  style.TabRounding = 4.0f;
  style.TabBorderSize = 0.0f;
  style.TabMinWidthForCloseButton = 0.0f;
  style.ColorButtonPosition = ImGuiDir_Right;
  style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
  style.SelectableTextAlign = ImVec2(0.0f, 0.0f);

  style.Colors[ImGuiCol_Text] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
  style.Colors[ImGuiCol_TextDisabled] = ImVec4(
      0.6000000238418579f, 0.6000000238418579f, 0.6000000238418579f, 1.0f);
  style.Colors[ImGuiCol_WindowBg] = ImVec4(
      0.9372549057006836f, 0.9372549057006836f, 0.9372549057006836f, 1.0f);
  style.Colors[ImGuiCol_ChildBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
  style.Colors[ImGuiCol_PopupBg] =
      ImVec4(1.0f, 1.0f, 1.0f, 0.9800000190734863f);
  style.Colors[ImGuiCol_Border] = ImVec4(0.0f, 0.0f, 0.0f, 0.300000011920929f);
  style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
  style.Colors[ImGuiCol_FrameBg] = ImVec4(
      0.9098712205886841f, 0.9098621010780334f, 0.9098621010780334f, 1.0f);
  style.Colors[ImGuiCol_FrameBgHovered] =
      ImVec4(0.412013053894043f, 0.4120149910449982f, 0.4120171666145325f,
             0.4000000059604645f);
  style.Colors[ImGuiCol_FrameBgActive] =
      ImVec4(0.5751015543937683f, 0.5751041769981384f, 0.5751073360443115f,
             0.6700000166893005f);
  style.Colors[ImGuiCol_TitleBg] =
      ImVec4(0.95686274766922f, 0.95686274766922f, 0.95686274766922f, 1.0f);
  style.Colors[ImGuiCol_TitleBgActive] = ImVec4(
      0.8196078538894653f, 0.8196078538894653f, 0.8196078538894653f, 1.0f);
  style.Colors[ImGuiCol_TitleBgCollapsed] =
      ImVec4(1.0f, 1.0f, 1.0f, 0.5099999904632568f);
  style.Colors[ImGuiCol_MenuBarBg] = ImVec4(
      0.8588235378265381f, 0.8588235378265381f, 0.8588235378265381f, 1.0f);
  style.Colors[ImGuiCol_ScrollbarBg] =
      ImVec4(0.9764705896377563f, 0.9764705896377563f, 0.9764705896377563f,
             0.5299999713897705f);
  style.Colors[ImGuiCol_ScrollbarGrab] =
      ImVec4(0.686274528503418f, 0.686274528503418f, 0.686274528503418f,
             0.800000011920929f);
  style.Colors[ImGuiCol_ScrollbarGrabHovered] =
      ImVec4(0.4862745106220245f, 0.4862745106220245f, 0.4862745106220245f,
             0.800000011920929f);
  style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(
      0.4862745106220245f, 0.4862745106220245f, 0.4862745106220245f, 1.0f);
  style.Colors[ImGuiCol_CheckMark] = ImVec4(
      0.1199690774083138f, 0.716738224029541f, 0.3095009922981262f, 1.0f);
  style.Colors[ImGuiCol_SliderGrab] = ImVec4(
      0.467806488275528f, 0.4678086936473846f, 0.4678111672401428f, 1.0f);
  style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(
      0.1640111058950424f, 0.1714581996202469f, 0.1802574992179871f, 1.0f);
  style.Colors[ImGuiCol_Button] =
      ImVec4(0.4549310505390167f, 0.4549332857131958f, 0.454935610294342f,
             0.4000000059604645f);
  style.Colors[ImGuiCol_ButtonHovered] = ImVec4(
      0.901278555393219f, 0.9012831449508667f, 0.9012875556945801f, 1.0f);
  style.Colors[ImGuiCol_ButtonActive] = ImVec4(
      0.7725244760513306f, 0.7725285887718201f, 0.7725322246551514f, 1.0f);
  style.Colors[ImGuiCol_Header] =
      ImVec4(0.4935572743415833f, 0.493559867143631f, 0.4935622215270996f,
             0.3100000023841858f);
  style.Colors[ImGuiCol_HeaderHovered] =
      ImVec4(0.4635146856307983f, 0.4635172486305237f, 0.4635193347930908f,
             0.800000011920929f);
  style.Colors[ImGuiCol_HeaderActive] =
      ImVec4(0.6909871101379395f, 0.6909801959991455f, 0.6909801959991455f,
             0.800000011920929f);
  style.Colors[ImGuiCol_Separator] =
      ImVec4(0.3882353007793427f, 0.3882353007793427f, 0.3882353007793427f,
             0.6200000047683716f);
  style.Colors[ImGuiCol_SeparatorHovered] =
      ImVec4(0.2102983444929123f, 0.2102994173765182f, 0.2103004455566406f,
             0.7799999713897705f);
  style.Colors[ImGuiCol_SeparatorActive] = ImVec4(
      0.3347606062889099f, 0.3347622454166412f, 0.3347639441490173f, 1.0f);
  style.Colors[ImGuiCol_ResizeGrip] =
      ImVec4(0.3490196168422699f, 0.3490196168422699f, 0.3490196168422699f,
             0.1700000017881393f);
  style.Colors[ImGuiCol_ResizeGripHovered] =
      ImVec4(0.2317573428153992f, 0.2317584306001663f, 0.2317596673965454f,
             0.6700000166893005f);
  style.Colors[ImGuiCol_ResizeGripActive] =
      ImVec4(0.09012787789106369f, 0.09012828767299652f, 0.09012877941131592f,
             0.949999988079071f);
  style.Colors[ImGuiCol_Tab] = ImVec4(0.6566457748413086f, 0.6566492319107056f,
                                      0.6566523313522339f, 0.9309999942779541f);
  style.Colors[ImGuiCol_TabHovered] =
      ImVec4(0.2875507771968842f, 0.2875520884990692f, 0.2875536680221558f,
             0.800000011920929f);
  style.Colors[ImGuiCol_TabActive] = ImVec4(
      0.8411933183670044f, 0.8411974310874939f, 0.8412017226219177f, 1.0f);
  style.Colors[ImGuiCol_TabUnfocused] =
      ImVec4(0.9176470637321472f, 0.9254902005195618f, 0.9333333373069763f,
             0.9861999750137329f);
  style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(
      0.6008523106575012f, 0.6008550524711609f, 0.6008583307266235f, 1.0f);
  style.Colors[ImGuiCol_PlotLines] = ImVec4(
      0.3882353007793427f, 0.3882353007793427f, 0.3882353007793427f, 1.0f);
  style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(
      0.6995707750320435f, 0.5437692403793335f, 0.5224262475967407f, 1.0f);
  style.Colors[ImGuiCol_PlotHistogram] = ImVec4(
      0.5534453988075256f, 0.6540425419807434f, 0.7768239974975586f, 1.0f);
  style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(
      0.7725322246551514f, 0.7725282907485962f, 0.7725244760513306f, 1.0f);
  style.Colors[ImGuiCol_TableHeaderBg] = ImVec4(
      0.6523540019989014f, 0.6523575186729431f, 0.6523605585098267f, 1.0f);
  style.Colors[ImGuiCol_TableBorderStrong] = ImVec4(
      0.6051441431045532f, 0.6051441431045532f, 0.6051502227783203f, 1.0f);
  style.Colors[ImGuiCol_TableBorderLight] = ImVec4(
      0.7338982224464417f, 0.7338982224464417f, 0.733905553817749f, 1.0f);
  style.Colors[ImGuiCol_TableRowBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
  style.Colors[ImGuiCol_TableRowBgAlt] =
      ImVec4(0.2980392277240753f, 0.2980392277240753f, 0.2980392277240753f,
             0.09000000357627869f);
  style.Colors[ImGuiCol_TextSelectedBg] =
      ImVec4(0.3519278168678284f, 0.3519294559955597f, 0.3519313335418701f,
             0.3499999940395355f);
  style.Colors[ImGuiCol_DragDropTarget] =
      ImVec4(0.3476360142230988f, 0.3476377129554749f, 0.3476395010948181f,
             0.949999988079071f);
  style.Colors[ImGuiCol_NavHighlight] =
      ImVec4(0.412013053894043f, 0.4120149612426758f, 0.4120171666145325f,
             0.800000011920929f);
  style.Colors[ImGuiCol_NavWindowingHighlight] =
      ImVec4(0.6980392336845398f, 0.6980392336845398f, 0.6980392336845398f,
             0.699999988079071f);
  style.Colors[ImGuiCol_NavWindowingDimBg] =
      ImVec4(0.2000000029802322f, 0.2000000029802322f, 0.2000000029802322f,
             0.2000000029802322f);
  style.Colors[ImGuiCol_ModalWindowDimBg] =
      ImVec4(0.2000000029802322f, 0.2000000029802322f, 0.2000000029802322f,
             0.3499999940395355f);
}

} // namespace debugger
