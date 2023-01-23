<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.4.2">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="yes" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="16" fill="1" visible="no" active="no"/>
<layer number="3" name="Route3" color="17" fill="1" visible="no" active="no"/>
<layer number="4" name="Route4" color="18" fill="1" visible="no" active="no"/>
<layer number="5" name="Route5" color="19" fill="1" visible="no" active="no"/>
<layer number="6" name="Route6" color="25" fill="1" visible="no" active="no"/>
<layer number="7" name="Route7" color="26" fill="1" visible="no" active="no"/>
<layer number="8" name="Route8" color="27" fill="1" visible="no" active="no"/>
<layer number="9" name="Route9" color="28" fill="1" visible="no" active="no"/>
<layer number="10" name="Route10" color="29" fill="1" visible="no" active="no"/>
<layer number="11" name="Route11" color="30" fill="1" visible="no" active="no"/>
<layer number="12" name="Route12" color="20" fill="1" visible="no" active="no"/>
<layer number="13" name="Route13" color="21" fill="1" visible="no" active="no"/>
<layer number="14" name="Route14" color="22" fill="1" visible="no" active="no"/>
<layer number="15" name="Route15" color="23" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="24" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="Frame">
<packages>
</packages>
<symbols>
<symbol name="A3">
<wire x1="50" y1="6" x2="50" y2="0" width="0.2" layer="94"/>
<wire x1="100" y1="6" x2="100" y2="0" width="0.2" layer="94"/>
<wire x1="150" y1="6" x2="150" y2="0" width="0.2" layer="94"/>
<wire x1="200" y1="6" x2="200" y2="0" width="0.2" layer="94"/>
<wire x1="250" y1="6" x2="250" y2="0" width="0.2" layer="94"/>
<wire x1="300" y1="6" x2="300" y2="0" width="0.2" layer="94"/>
<wire x1="350" y1="6" x2="350" y2="0" width="0.2" layer="94"/>
<wire x1="50" y1="277" x2="50" y2="271" width="0.2" layer="94"/>
<wire x1="100" y1="271" x2="100" y2="277" width="0.2" layer="94"/>
<wire x1="150" y1="271" x2="150" y2="277" width="0.2" layer="94"/>
<wire x1="200" y1="271" x2="200" y2="277" width="0.2" layer="94"/>
<wire x1="250" y1="271" x2="250" y2="277" width="0.2" layer="94"/>
<wire x1="300" y1="271" x2="300" y2="277" width="0.2" layer="94"/>
<wire x1="350" y1="271" x2="350" y2="277" width="0.2" layer="94"/>
<wire x1="0" y1="231" x2="6" y2="231" width="0.2" layer="94"/>
<wire x1="0" y1="185" x2="6" y2="185" width="0.2" layer="94"/>
<wire x1="0" y1="139" x2="6" y2="139" width="0.2" layer="94"/>
<wire x1="0" y1="93" x2="6" y2="93" width="0.2" layer="94"/>
<wire x1="0" y1="47" x2="6" y2="47" width="0.2" layer="94"/>
<wire x1="394" y1="231" x2="400" y2="231" width="0.2" layer="94"/>
<wire x1="394" y1="185" x2="400" y2="185" width="0.2" layer="94"/>
<wire x1="394" y1="139" x2="400" y2="139" width="0.2" layer="94"/>
<wire x1="394" y1="93" x2="400" y2="93" width="0.2" layer="94"/>
<wire x1="394" y1="47" x2="400" y2="47" width="0.2" layer="94"/>
<wire x1="6" y1="6" x2="50" y2="6" width="0.2" layer="94"/>
<wire x1="50" y1="6" x2="100" y2="6" width="0.2" layer="94"/>
<wire x1="100" y1="6" x2="150" y2="6" width="0.2" layer="94"/>
<wire x1="150" y1="6" x2="200" y2="6" width="0.2" layer="94"/>
<wire x1="200" y1="6" x2="250" y2="6" width="0.2" layer="94"/>
<wire x1="250" y1="6" x2="300" y2="6" width="0.2" layer="94"/>
<wire x1="300" y1="6" x2="311" y2="6" width="0.2" layer="94"/>
<wire x1="311" y1="6" x2="350" y2="6" width="0.2" layer="94"/>
<wire x1="350" y1="6" x2="365" y2="6" width="0.2" layer="94"/>
<wire x1="365" y1="6" x2="394" y2="6" width="0.2" layer="94"/>
<wire x1="394" y1="6" x2="394" y2="26" width="0.2" layer="94"/>
<wire x1="394" y1="26" x2="394" y2="36" width="0.2" layer="94"/>
<wire x1="394" y1="36" x2="394" y2="47" width="0.2" layer="94"/>
<wire x1="394" y1="47" x2="394" y2="93" width="0.2" layer="94"/>
<wire x1="394" y1="93" x2="394" y2="139" width="0.2" layer="94"/>
<wire x1="394" y1="139" x2="394" y2="185" width="0.2" layer="94"/>
<wire x1="394" y1="185" x2="394" y2="231" width="0.2" layer="94"/>
<wire x1="394" y1="231" x2="394" y2="271" width="0.2" layer="94"/>
<wire x1="394" y1="271" x2="350" y2="271" width="0.2" layer="94"/>
<wire x1="350" y1="271" x2="300" y2="271" width="0.2" layer="94"/>
<wire x1="300" y1="271" x2="250" y2="271" width="0.2" layer="94"/>
<wire x1="250" y1="271" x2="200" y2="271" width="0.2" layer="94"/>
<wire x1="200" y1="271" x2="150" y2="271" width="0.2" layer="94"/>
<wire x1="150" y1="271" x2="100" y2="271" width="0.2" layer="94"/>
<wire x1="100" y1="271" x2="50" y2="271" width="0.2" layer="94"/>
<wire x1="50" y1="271" x2="6" y2="271" width="0.2" layer="94"/>
<wire x1="6" y1="271" x2="6" y2="231" width="0.2" layer="94"/>
<wire x1="6" y1="231" x2="6" y2="185" width="0.2" layer="94"/>
<wire x1="6" y1="185" x2="6" y2="139" width="0.2" layer="94"/>
<wire x1="6" y1="139" x2="6" y2="93" width="0.2" layer="94"/>
<wire x1="6" y1="93" x2="6" y2="47" width="0.2" layer="94"/>
<wire x1="6" y1="47" x2="6" y2="6" width="0.2" layer="94"/>
<wire x1="0" y1="0" x2="199" y2="0" width="0.5" layer="94"/>
<wire x1="199" y1="0" x2="201" y2="0" width="0.5" layer="94"/>
<wire x1="201" y1="0" x2="400" y2="0" width="0.5" layer="94"/>
<wire x1="400" y1="0" x2="400" y2="277" width="0.5" layer="94"/>
<wire x1="400" y1="277" x2="0" y2="277" width="0.5" layer="94"/>
<wire x1="0" y1="277" x2="0" y2="140" width="0.5" layer="94"/>
<text x="3" y="254" size="1.778" layer="94" align="center">A</text>
<text x="397" y="254" size="1.778" layer="94" align="center">A</text>
<text x="3" y="208" size="1.778" layer="94" align="center">B</text>
<text x="397" y="208" size="1.778" layer="94" align="center">B</text>
<text x="3" y="162" size="1.778" layer="94" align="center">C</text>
<text x="397" y="162" size="1.778" layer="94" align="center">C</text>
<text x="3" y="115" size="1.778" layer="94" align="center">D</text>
<text x="397" y="116" size="1.778" layer="94" align="center">D</text>
<text x="3" y="70" size="1.778" layer="94" align="center">E</text>
<text x="397" y="70" size="1.778" layer="94" align="center">E</text>
<text x="3" y="24" size="1.778" layer="94" align="center">F</text>
<text x="397" y="24" size="1.778" layer="94" align="center">F</text>
<text x="25" y="274" size="1.778" layer="94" align="center">1</text>
<text x="25" y="3" size="1.778" layer="94" align="center">1</text>
<text x="75" y="3" size="1.778" layer="94" align="center">2</text>
<text x="75" y="274" size="1.778" layer="94" align="center">2</text>
<text x="125" y="274" size="1.778" layer="94" align="center">3</text>
<text x="125" y="3" size="1.778" layer="94" align="center">3</text>
<text x="174" y="3" size="1.778" layer="94" align="center">4</text>
<text x="175" y="274" size="1.778" layer="94" align="center">4</text>
<text x="225" y="274" size="1.778" layer="94" align="center">5</text>
<text x="225" y="3" size="1.778" layer="94" align="center">5</text>
<text x="275" y="3" size="1.778" layer="94" align="center">6</text>
<text x="275" y="274" size="1.778" layer="94" align="center">6</text>
<text x="325" y="3" size="1.778" layer="94" align="center">7</text>
<text x="325" y="274" size="1.778" layer="94" align="center">7</text>
<text x="375" y="3" size="1.778" layer="94" align="center">8</text>
<text x="375" y="274" size="1.778" layer="94" align="center">8</text>
<text x="312" y="19.5" size="4" layer="94" align="center-left">&gt;DRAWING_NAME</text>
<text x="312" y="9.5" size="4" layer="94" align="center-left">&gt;LAST_DATE_TIME</text>
<text x="366" y="9.5" size="5" layer="94" align="center-left">&gt;SHEET</text>
<text x="366" y="14" size="2" layer="94" align="center-left">Sheet</text>
<wire x1="0" y1="140" x2="0" y2="138" width="0.5" layer="94"/>
<wire x1="0" y1="138" x2="0" y2="0" width="0.5" layer="94"/>
<wire x1="365" y1="16" x2="365" y2="26" width="0.2" layer="94"/>
<wire x1="365" y1="26" x2="365" y2="36" width="0.2" layer="94"/>
<wire x1="365" y1="16" x2="394" y2="16" width="0.2" layer="94"/>
<wire x1="365" y1="36" x2="311" y2="36" width="0.2" layer="94"/>
<wire x1="365" y1="26" x2="311" y2="26" width="0.2" layer="94"/>
<wire x1="365" y1="16" x2="311" y2="16" width="0.2" layer="94"/>
<text x="312" y="34" size="2" layer="94" align="center-left">Author</text>
<text x="366" y="29.5" size="5" layer="94" align="center-left">A3</text>
<text x="366" y="19.5" size="5" layer="94" align="center-left">mm</text>
<text x="366" y="24" size="2" layer="94" align="center-left">Unit</text>
<text x="366" y="34" size="2" layer="94" align="center-left">Size</text>
<wire x1="365" y1="26" x2="394" y2="26" width="0.2" layer="94"/>
<wire x1="365" y1="36" x2="394" y2="36" width="0.2" layer="94"/>
<text x="312" y="24" size="2" layer="94" align="center-left">Drawing Name</text>
<text x="312" y="14" size="2" layer="94" align="center-left">Last Date Time</text>
<wire x1="365" y1="6" x2="365" y2="16" width="0.2" layer="94"/>
<wire x1="311" y1="36" x2="311" y2="6" width="0.2" layer="94"/>
<text x="312" y="29.5" size="4" layer="94" align="center-left">Ryuya Hirayama</text>
<polygon width="0.2" layer="94">
<vertex x="199" y="0"/>
<vertex x="200" y="5"/>
<vertex x="201" y="0"/>
</polygon>
<polygon width="0.2" layer="94">
<vertex x="0" y="140"/>
<vertex x="5" y="139"/>
<vertex x="0" y="138"/>
</polygon>
<polygon width="0.2" layer="94">
<vertex x="199" y="277"/>
<vertex x="200" y="272"/>
<vertex x="201" y="277"/>
</polygon>
<polygon width="0.2" layer="94">
<vertex x="400" y="140"/>
<vertex x="395" y="139"/>
<vertex x="400" y="138"/>
</polygon>
</symbol>
</symbols>
<devicesets>
<deviceset name="A3_FRAME">
<gates>
<gate name="G$1" symbol="A3" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="FT232" urn="urn:adsk.eagle:library:12233571">
<packages>
<package name="QFN-32" urn="urn:adsk.eagle:footprint:12233572/1" library_version="1" library_locally_modified="yes">
<smd name="P$1" x="-2.55" y="1.75" dx="0.6" dy="0.3" layer="1"/>
<smd name="P$2" x="-2.55" y="1.25" dx="0.6" dy="0.3" layer="1"/>
<smd name="P$3" x="-2.55" y="0.75" dx="0.6" dy="0.3" layer="1"/>
<smd name="P$4" x="-2.55" y="0.25" dx="0.6" dy="0.3" layer="1"/>
<smd name="P$5" x="-2.55" y="-0.25" dx="0.6" dy="0.3" layer="1"/>
<smd name="P$6" x="-2.55" y="-0.75" dx="0.6" dy="0.3" layer="1"/>
<smd name="P$7" x="-2.55" y="-1.25" dx="0.6" dy="0.3" layer="1"/>
<smd name="P$8" x="-2.55" y="-1.75" dx="0.6" dy="0.3" layer="1"/>
<smd name="P$9" x="-1.75" y="-2.55" dx="0.6" dy="0.3" layer="1" rot="R90"/>
<smd name="P$10" x="-1.25" y="-2.55" dx="0.6" dy="0.3" layer="1" rot="R90"/>
<smd name="P$11" x="-0.75" y="-2.55" dx="0.6" dy="0.3" layer="1" rot="R90"/>
<smd name="P$12" x="-0.25" y="-2.55" dx="0.6" dy="0.3" layer="1" rot="R90"/>
<smd name="P$13" x="0.25" y="-2.55" dx="0.6" dy="0.3" layer="1" rot="R90"/>
<smd name="P$14" x="0.75" y="-2.55" dx="0.6" dy="0.3" layer="1" rot="R90"/>
<smd name="P$15" x="1.25" y="-2.55" dx="0.6" dy="0.3" layer="1" rot="R90"/>
<smd name="P$16" x="1.75" y="-2.55" dx="0.6" dy="0.3" layer="1" rot="R90"/>
<smd name="P$17" x="2.55" y="-1.75" dx="0.6" dy="0.3" layer="1" rot="R180"/>
<smd name="P$18" x="2.55" y="-1.25" dx="0.6" dy="0.3" layer="1" rot="R180"/>
<smd name="P$19" x="2.55" y="-0.75" dx="0.6" dy="0.3" layer="1" rot="R180"/>
<smd name="P$20" x="2.55" y="-0.25" dx="0.6" dy="0.3" layer="1" rot="R180"/>
<smd name="P$21" x="2.55" y="0.25" dx="0.6" dy="0.3" layer="1" rot="R180"/>
<smd name="P$22" x="2.55" y="0.75" dx="0.6" dy="0.3" layer="1" rot="R180"/>
<smd name="P$23" x="2.55" y="1.25" dx="0.6" dy="0.3" layer="1" rot="R180"/>
<smd name="P$24" x="2.55" y="1.75" dx="0.6" dy="0.3" layer="1" rot="R180"/>
<smd name="P$25" x="1.75" y="2.55" dx="0.6" dy="0.3" layer="1" rot="R270"/>
<smd name="P$26" x="1.25" y="2.55" dx="0.6" dy="0.3" layer="1" rot="R270"/>
<smd name="P$27" x="0.75" y="2.55" dx="0.6" dy="0.3" layer="1" rot="R270"/>
<smd name="P$28" x="0.25" y="2.55" dx="0.6" dy="0.3" layer="1" rot="R270"/>
<smd name="P$29" x="-0.25" y="2.55" dx="0.6" dy="0.3" layer="1" rot="R270"/>
<smd name="P$30" x="-0.75" y="2.55" dx="0.6" dy="0.3" layer="1" rot="R270"/>
<smd name="P$31" x="-1.25" y="2.55" dx="0.6" dy="0.3" layer="1" rot="R270"/>
<smd name="P$32" x="-1.75" y="2.55" dx="0.6" dy="0.3" layer="1" rot="R270"/>
<smd name="P$33" x="0" y="0" dx="3.3" dy="3.3" layer="1"/>
<wire x1="2.2" y1="2.5" x2="2.5" y2="2.5" width="0.127" layer="21"/>
<wire x1="2.5" y1="2.5" x2="2.5" y2="2.2" width="0.127" layer="21"/>
<wire x1="-2.5" y1="-2.2" x2="-2.5" y2="-2.5" width="0.127" layer="21"/>
<wire x1="-2.5" y1="-2.5" x2="-2.2" y2="-2.5" width="0.127" layer="21"/>
<wire x1="-2.2" y1="2.5" x2="-2.5" y2="2.5" width="0.127" layer="21"/>
<wire x1="-2.5" y1="2.5" x2="-2.5" y2="2.2" width="0.127" layer="21"/>
<wire x1="2.2" y1="-2.5" x2="2.5" y2="-2.5" width="0.127" layer="21"/>
<wire x1="2.5" y1="-2.5" x2="2.5" y2="-2.2" width="0.127" layer="21"/>
<circle x="-2.81" y="2.8" radius="0.058309375" width="0.127" layer="21"/>
</package>
</packages>
<packages3d>
<package3d name="QFN-32" urn="urn:adsk.eagle:package:12233574/2" type="box" library_version="1" library_locally_modified="yes">
<packageinstances>
<packageinstance name="QFN-32"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="FT232RQ" urn="urn:adsk.eagle:symbol:12233573/1" locally_modified="yes" library_version="1" library_locally_modified="yes">
<pin name="VCCIO" x="-33.02" y="17.78" length="short"/>
<pin name="RXD" x="-33.02" y="12.7" length="short"/>
<pin name="RI#" x="-33.02" y="7.62" length="short"/>
<pin name="GND1" x="-33.02" y="2.54" length="short"/>
<pin name="NC1" x="-33.02" y="-2.54" length="short"/>
<pin name="DSR#" x="-33.02" y="-7.62" length="short"/>
<pin name="DCD#" x="-33.02" y="-12.7" length="short"/>
<pin name="CTS#" x="-33.02" y="-17.78" length="short"/>
<pin name="CBUS4" x="-17.78" y="-33.02" length="short" rot="R90"/>
<pin name="CBUS2" x="-12.7" y="-33.02" length="short" rot="R90"/>
<pin name="CBUS3" x="-7.62" y="-33.02" length="short" rot="R90"/>
<pin name="NC2" x="-2.54" y="-33.02" length="short" rot="R90"/>
<pin name="NC3" x="2.54" y="-33.02" length="short" rot="R90"/>
<pin name="USBDP" x="7.62" y="-33.02" length="short" rot="R90"/>
<pin name="USBDM" x="12.7" y="-33.02" length="short" rot="R90"/>
<pin name="3V3OUT" x="17.78" y="-33.02" length="short" rot="R90"/>
<pin name="GND2" x="33.02" y="-17.78" length="short" rot="R180"/>
<pin name="RESET#" x="33.02" y="-12.7" length="short" rot="R180"/>
<pin name="VCC" x="33.02" y="-7.62" length="short" rot="R180"/>
<pin name="GND3" x="33.02" y="-2.54" length="short" rot="R180"/>
<pin name="CBUS1" x="33.02" y="2.54" length="short" rot="R180"/>
<pin name="CBUS0" x="33.02" y="7.62" length="short" rot="R180"/>
<pin name="NC4" x="33.02" y="12.7" length="short" rot="R180"/>
<pin name="AGND" x="33.02" y="17.78" length="short" rot="R180"/>
<pin name="NC5" x="17.78" y="33.02" length="short" rot="R270"/>
<pin name="TEST" x="12.7" y="33.02" length="short" rot="R270"/>
<pin name="OSCI" x="7.62" y="33.02" length="short" rot="R270"/>
<pin name="OSCO" x="2.54" y="33.02" length="short" rot="R270"/>
<pin name="NC6" x="-2.54" y="33.02" length="short" rot="R270"/>
<pin name="TXD" x="-7.62" y="33.02" length="short" rot="R270"/>
<pin name="DTR#" x="-12.7" y="33.02" length="short" rot="R270"/>
<pin name="RTS#" x="-17.78" y="33.02" length="short" rot="R270"/>
<pin name="THPAD" x="27.94" y="-35.56" length="short" rot="R90"/>
<wire x1="-30.48" y1="30.48" x2="30.48" y2="30.48" width="0.254" layer="94"/>
<wire x1="30.48" y1="30.48" x2="30.48" y2="-30.48" width="0.254" layer="94"/>
<wire x1="30.48" y1="-30.48" x2="-30.48" y2="-30.48" width="0.254" layer="94"/>
<wire x1="-30.48" y1="-30.48" x2="-30.48" y2="30.48" width="0.254" layer="94"/>
<wire x1="25.4" y1="-33.02" x2="30.48" y2="-33.02" width="0.254" layer="94"/>
<text x="0" y="-2.54" size="1.27" layer="95" align="center">&gt;NAME</text>
<text x="0" y="2.54" size="1.27" layer="96" align="center">&gt;VALUE</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="FT232RQ" prefix="U" library_version="1" library_locally_modified="yes">
<gates>
<gate name="G$1" symbol="FT232RQ" x="0" y="0"/>
</gates>
<devices>
<device name="" package="QFN-32">
<connects>
<connect gate="G$1" pin="3V3OUT" pad="P$16"/>
<connect gate="G$1" pin="AGND" pad="P$24"/>
<connect gate="G$1" pin="CBUS0" pad="P$22"/>
<connect gate="G$1" pin="CBUS1" pad="P$21"/>
<connect gate="G$1" pin="CBUS2" pad="P$10"/>
<connect gate="G$1" pin="CBUS3" pad="P$11"/>
<connect gate="G$1" pin="CBUS4" pad="P$9"/>
<connect gate="G$1" pin="CTS#" pad="P$8"/>
<connect gate="G$1" pin="DCD#" pad="P$7"/>
<connect gate="G$1" pin="DSR#" pad="P$6"/>
<connect gate="G$1" pin="DTR#" pad="P$31"/>
<connect gate="G$1" pin="GND1" pad="P$4"/>
<connect gate="G$1" pin="GND2" pad="P$17"/>
<connect gate="G$1" pin="GND3" pad="P$20"/>
<connect gate="G$1" pin="NC1" pad="P$5"/>
<connect gate="G$1" pin="NC2" pad="P$12"/>
<connect gate="G$1" pin="NC3" pad="P$13"/>
<connect gate="G$1" pin="NC4" pad="P$23"/>
<connect gate="G$1" pin="NC5" pad="P$25"/>
<connect gate="G$1" pin="NC6" pad="P$29"/>
<connect gate="G$1" pin="OSCI" pad="P$27"/>
<connect gate="G$1" pin="OSCO" pad="P$28"/>
<connect gate="G$1" pin="RESET#" pad="P$18"/>
<connect gate="G$1" pin="RI#" pad="P$3"/>
<connect gate="G$1" pin="RTS#" pad="P$32"/>
<connect gate="G$1" pin="RXD" pad="P$2"/>
<connect gate="G$1" pin="TEST" pad="P$26"/>
<connect gate="G$1" pin="THPAD" pad="P$33"/>
<connect gate="G$1" pin="TXD" pad="P$30"/>
<connect gate="G$1" pin="USBDM" pad="P$15"/>
<connect gate="G$1" pin="USBDP" pad="P$14"/>
<connect gate="G$1" pin="VCC" pad="P$19"/>
<connect gate="G$1" pin="VCCIO" pad="P$1"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:12233574/2"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="U$1" library="Frame" deviceset="A3_FRAME" device=""/>
<part name="U1" library="FT232" library_urn="urn:adsk.eagle:library:12233571" deviceset="FT232RQ" device="" package3d_urn="urn:adsk.eagle:package:12233574/2"/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="U$1" gate="G$1" x="0" y="0" smashed="yes">
<attribute name="DRAWING_NAME" x="312" y="19.5" size="4" layer="94" align="center-left"/>
<attribute name="LAST_DATE_TIME" x="312" y="9.5" size="4" layer="94" align="center-left"/>
<attribute name="SHEET" x="366" y="9.5" size="5" layer="94" align="center-left"/>
</instance>
<instance part="U1" gate="G$1" x="134.62" y="157.48" smashed="yes">
<attribute name="NAME" x="134.62" y="154.94" size="1.27" layer="95" align="center"/>
<attribute name="VALUE" x="134.62" y="160.02" size="1.27" layer="96" align="center"/>
</instance>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports the association of 3D packages
with devices in libraries, schematics, and board files. Those 3D
packages will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>
