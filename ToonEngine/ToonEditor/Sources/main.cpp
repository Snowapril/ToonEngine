#include "stdafx.h"
#include "ToonEditorRoot.h"

int main(void)
{
	ToonEditor::ToonEditorRoot editorRoot;

	if (!editorRoot.initialize(true, OBFUSCATE("ToonEngine"), OBFUSCATE("../Resources/engine_config.ini")))
	{
		return -1;
	}

	int exitCode = editorRoot.runMainLoop();
	return exitCode;
}