#pragma once

static int GetNextObjectId() {
	static int id = 0;
	return ++id;
}
