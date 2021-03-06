
#include <ros/ros.h>
#include <ros/package.h>

#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

#include <human_aware_navigation/TaskFinished.h>

#include <utilities/printer.hpp>

#include <sstream>
#include <string>     // std::string, std::to_string

using namespace ros;
using namespace std;

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

class GoalSender
{
public:
	GoalSender ();
	virtual ~GoalSender (){};

	void run();

	void automaticSendGoals();

private:

	NodeHandle                               m_nd;

	Subscriber								 m_sub_TaskFinished;

	vector<move_base_msgs::MoveBaseGoal>     goals;

	int										 goal_index;

	void taskFinishedClbk(const human_aware_navigation::TaskFinished &tf);

	void sendGoal();

};/* _goal_manager_HPP__ */
