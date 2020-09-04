#pragma once

namespace BEClient {
	enum class InstanceStatus {
		None,
		NotInitialized,
		SuccessfullyInitialized,
		Destroying,
		Destroyed
	};

	enum class RestartReason {
		UnknownRestartReason = -1,
		ServiceNotRunningProperly,
		ServiceNeedsToBeUpdated
	};
}