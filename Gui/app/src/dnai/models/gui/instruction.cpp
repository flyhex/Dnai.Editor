#include <QJsonObject>
#include <QJsonArray>
#include "dnai/models/gui/instruction.h"

namespace dnai
{
	namespace models
	{
		namespace gui
		{
			Instruction::Instruction(QObject* parent) : QObject(parent)
			{
			}

			void Instruction::serialize(QJsonObject& obj) const
			{
				QJsonArray inputs;
				foreach(const Input *input, m_data.inputs) {
					QJsonObject var;
					input->serialize(var);
					inputs.append(var);
				}

				QJsonArray outputs;
				foreach(const Output *output, m_data.outputs) {
					QJsonObject var;
					output->serialize(var);
					outputs.append(var);
				}

				obj["inputs"] = inputs;
				obj["outputs"] = outputs;
				QJsonObject temp;
				m_data.flowIn->serialize(temp);
				obj["flow_in"] = temp;
				m_data.flowOut->serialize(temp);
				obj["flow_out"] = temp;
				obj["instruction_id"] = m_data.instructionId;
			}

			void Instruction::_deserialize(const QJsonObject& obj)
			{
				foreach(auto input, obj["inputs"].toArray()) {
					m_data.inputs.append(Input::deserialize(input.toObject()));
		        }
				foreach(auto input, obj["m_outputs"].toArray()) {
					m_data.inputs.append(Input::deserialize(input.toObject()));
				}
				m_data.flowIn = Flow::deserialize(obj["flow_in"].toObject());
				m_data.flowOut = Flow::deserialize(obj["flow_out"].toObject());
				m_data.instructionId = obj["instruction_id"].toInt();
			}

			const data::Instruction& Instruction::data() const
			{
				return m_data;
			}

			bool Instruction::setData(const data::Instruction& data)
			{
                if (m_data == data)
                    return false;
				m_data = data;
                return true;
			}

            const QList<models::gui::Input*> &Instruction::inputs() const
			{
				return m_data.inputs;
			}

			bool Instruction::setInputs(const QList<models::gui::Input*>& inputs)
			{
				if (m_data.inputs == inputs)
					return false;
				m_data.inputs = inputs;
				return true;
			}

            const QList<models::gui::Output*> &Instruction::outputs() const
			{
				return m_data.outputs;
			}

			bool Instruction::setOutputs(const QList<models::gui::Output*>& outputs)
			{
				if (m_data.outputs == outputs)
					return false;
				m_data.outputs = outputs;
				return true;
			}

			models::gui::Flow* Instruction::flowIn() const
			{
				return m_data.flowIn;
			}

			bool Instruction::setFlowIn(models::gui::Flow* flow)
			{
				if (m_data.flowIn == flow)
					return false;
				m_data.flowIn = flow;
				return true;
			}

			models::gui::Flow* Instruction::flowOut() const
			{
				return m_data.flowOut;
			}

			bool Instruction::setFlowOut(models::gui::Flow* flow)
			{
				if (m_data.flowOut == flow)
					return false;
				m_data.flowOut = flow;
				return true;
			}
		}
	}
}