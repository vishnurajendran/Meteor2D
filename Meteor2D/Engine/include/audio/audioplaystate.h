#pragma once
namespace meteor {
	/**
	 * @brief This enum represents the AudioPlayable instance states.
	*/
	enum AudioPlayableState {
		/**
		 * @brief Initialised
		*/
		PLAYABLE_INIT,
		/**
		 * @brief Playback Stopped
		*/
		PLAYABLE_STOPPED,
		/**
		 * @brief Currently playing
		*/
		PLAYABLE_PLAYING,
		/**
		 * @brief Error State
		*/
		PLAYABLE_ERR
	};
}