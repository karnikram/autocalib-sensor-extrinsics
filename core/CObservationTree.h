#pragma once

#include "CObservationTreeItem.h"
#include "CUtils.h"
#include <interfaces/CTextObserver.h>

#include <mrpt/obs/CObservation3DRangeScan.h>
#include <mrpt/config/CConfigFile.h>
#include <Eigen/Core>

/**
 * Class for loading, storing, and synchronizing the observations from a rawlog file into a tree.
 * The class also maintains the relative transformations between all the sensors.
 */

class CObservationTree
{
    public:
	    CObservationTree();
		~CObservationTree();

		/**
		 * \brief loadTree loads the contents of the rawlog into the tree.
		 * \param rawlog_filename the rawlog file.
		 */
		void loadTree(const std::string &rawlog_filename, const mrpt::config::CConfigFile &config_file);

		/**
		 * Returns the root item of the tree.
		 */
		CObservationTreeItem *getRootItem() const;

		/**
		 * Returns the item at the given index in the tree.
		 * \param index the tree index.
		 */
		CObservationTreeItem *getItem(const int &index) const;

		/** Returns the count of total number of observations found in the rawlog. */
		int getObsCount() const;

		/** Returns a list of the unique sensor labels found in the rawlog. */
		std::vector<std::string> getSensorLabels() const;

		/** Returns the count of observations of each label found in the rawlog. */
		std::vector<int> getCountOfLabel() const;

		/** Returns the poses of the sensors found in the rawlog. */
		std::vector<Eigen::Matrix4f> getSensorPoses() const;

		/** Groups observations together based on their time stamp proximity.
		 * Stores the results back in the same tree.
		 * \param the labels of the sensors that are to be considered for grouping.
		 * \param max_delay Maximum allowable delay between observations.
		 */
		void syncObservations(const std::vector<std::string> &selected_sensor_labels, const int &max_delay);

		/** Returns the indices of the grouped observations with respect to the original tree. */
		std::vector<std::vector<int>> getSyncIndices() const;


    protected:

		/** The name of the file the rawlog was loaded from. */
		std::string m_rawlog_filename;

		/** The root parent item from which all the other observations originate. */
		CObservationTreeItem *m_rootitem;

		/** The total number of observations loaded from the rawlog. */
		int m_obs_count;

		/** The unique sensor labels found in the rawlog. */
		std::vector<std::string> m_sensor_labels;

		/** store count of observations of each observation type. */
		std::vector<int> m_count_of_label;

		/** bool to indicate whether the elements in the tree have been synchronized or not. */
		bool m_synced;

		/** m_sync_indices indices of the grouped (synchronized) observations with respect to the original tree, per sensor. */
		std::vector<std::vector<int>> m_sync_indices;

		/** the maximum allowable delay between observation items before they can be synced. */
		int m_sync_offset = -1;

		/** The [R,t] poses of the sensors found in the rawlog. */
		std::vector<Eigen::Matrix4f> m_sensor_poses;
};
