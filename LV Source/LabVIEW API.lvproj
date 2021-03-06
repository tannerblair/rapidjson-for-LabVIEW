﻿<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="16008000">
	<Property Name="CCSymbols" Type="Str">DEVELOPMENT,false;</Property>
	<Property Name="NI.LV.All.SourceOnly" Type="Bool">false</Property>
	<Property Name="NI.Project.Description" Type="Str"></Property>
	<Item Name="My Computer" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="Examples" Type="Folder">
			<Item Name="basic usage.vi" Type="VI" URL="../examples/basic usage.vi"/>
			<Item Name="manipulating json documents.vi" Type="VI" URL="../examples/manipulating json documents.vi"/>
			<Item Name="pointer basics.vi" Type="VI" URL="../examples/pointer basics.vi"/>
			<Item Name="Working With Arrays.vi" Type="VI" URL="../examples/Working With Arrays.vi"/>
			<Item Name="working with objects.vi" Type="VI" URL="../examples/working with objects.vi"/>
		</Item>
		<Item Name="Move DLL" Type="Folder">
			<Item Name="Move DLL to Resource.vi" Type="VI" URL="../Move DLL to Resource.vi"/>
		</Item>
		<Item Name="test" Type="Folder">
			<Item Name="dynamic parse test.vi" Type="VI" URL="../dynamic parse test.vi"/>
			<Item Name="insert and parse tests.vi" Type="VI" URL="../insert and parse tests.vi"/>
			<Item Name="insert anything tests.vi" Type="VI" URL="../test files/insert anything tests.vi"/>
			<Item Name="large.json" Type="Document" URL="../test files/large.json"/>
			<Item Name="read large file.vi" Type="VI" URL="../read large file.vi"/>
			<Item Name="scratch.vi" Type="VI" URL="../scratch.vi"/>
		</Item>
		<Item Name="JSON Document.lvclass" Type="LVClass" URL="../API/JSON Document Class/JSON Document.lvclass"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="Error Cluster From Error Code.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Error Cluster From Error Code.vi"/>
				<Item Name="NI_Data Type.lvlib" Type="Library" URL="/&lt;vilib&gt;/Utility/Data Type/NI_Data Type.lvlib"/>
			</Item>
		</Item>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
