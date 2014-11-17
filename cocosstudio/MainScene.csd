<GameProjectFile>
  <PropertyGroup Type="Scene" Name="MainScene" ID="a7730870-8bfb-4ad5-8543-273ef7e2e0fe" Version="2.0.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="10" Speed="1">
        <Timeline ActionTag="5" FrameType="PositionFrame">
          <PointFrame FrameIndex="0" X="480" Y="320" />
          <PointFrame FrameIndex="10" X="480" Y="320" />
        </Timeline>
        <Timeline ActionTag="5" FrameType="ScaleFrame">
          <PointFrame FrameIndex="0" X="1" Y="1" />
          <PointFrame FrameIndex="10" X="1" Y="1" />
        </Timeline>
        <Timeline ActionTag="5" FrameType="RotationSkewFrame">
          <PointFrame FrameIndex="0" X="0" Y="0" />
          <PointFrame FrameIndex="10" X="0" Y="0" />
        </Timeline>
      </Animation>
      <ObjectData Name="Scene" CanEdit="False" FrameEvent="" ctype="SingleNodeObjectData">
        <Position X="0" Y="0" />
        <Scale ScaleX="1" ScaleY="1" />
        <AnchorPoint />
        <CColor A="255" R="255" G="255" B="255" />
        <Size X="960" Y="640" />
        <PrePosition X="0" Y="0" />
        <PreSize X="0" Y="0" />
        <Children>
          <NodeObjectData Name="LoadingBar_1" ActionTag="5" FrameEvent="" Tag="3" ObjectIndex="1" PrePositionEnabled="True" ProgressInfo="100" ctype="LoadingBarObjectData">
            <Position X="480" Y="320" />
            <Scale ScaleX="1" ScaleY="1" />
            <AnchorPoint ScaleX="0.5" ScaleY="0.5" />
            <CColor A="255" R="255" G="255" B="255" />
            <Size X="200" Y="14" />
            <PrePosition X="0.5" Y="0.5" />
            <PreSize X="0" Y="0" />
            <ImageFileData Type="Default" Path="Default/LoadingBarFile.png" />
          </NodeObjectData>
          <NodeObjectData Name="Slider_1" ActionTag="6" FrameEvent="" Tag="4" ObjectIndex="1" PrePositionEnabled="True" TouchEnable="True" PercentInfo="50" ctype="SliderObjectData">
            <Position X="480" Y="128" />
            <Scale ScaleX="1" ScaleY="1" />
            <AnchorPoint ScaleX="0.5" ScaleY="0.5" />
            <CColor A="255" R="255" G="255" B="255" />
            <Size X="200" Y="14" />
            <PrePosition X="0.5" Y="0.2" />
            <PreSize X="0" Y="0" />
            <BackGroundData Type="Default" Path="Default/Slider_Back.png" />
            <BallNormalData Type="Default" Path="Default/SliderNode_Normal.png" />
            <BallPressedData Type="Default" Path="Default/SliderNode_Press.png" />
            <BallDisabledData Type="Default" Path="Default/SliderNode_Disable.png" />
            <ProgressBarData Type="Default" Path="Default/Slider_PressBar.png" />
          </NodeObjectData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>