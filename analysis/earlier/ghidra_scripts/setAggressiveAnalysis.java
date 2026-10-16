// Pre-script: enable aggressive analysis options for MSPR EBOOT.
// @category: MSPR

import ghidra.app.script.GhidraScript;

public class setAggressiveAnalysis extends GhidraScript {

	@Override
	public void run() throws Exception {
		setAnalysisOption(currentProgram, "Aggressive Instruction Finder", "true");
		setAnalysisOption(currentProgram, "Decompiler Parameter ID", "true");
		setAnalysisOption(currentProgram, "Shared Return Calls", "true");
		setAnalysisOption(currentProgram, "Function Start Search", "true");
		setAnalysisOption(currentProgram, "Function Start Search Should Continue", "true");
		setAnalysisOption(currentProgram, "Non-Returning Functions - Discovered", "true");
		setAnalysisOption(currentProgram, "Embedded Media", "false");
		setAnalysisOption(currentProgram, "ASCII Strings", "true");
		println("aggressive analysis options set");
	}
}
