#ifndef __LIB_MEALY_H__
#define __LIB_MEALY_H__
#include <stdint.h>
#ifdef __cplusplus
extern "C"
{
#endif
	/// @brief ״̬��ת�Ʊ����͡�
	typedef struct
	{
		/// @brief ������
		/// @param from ��ǰ״̬��
		/// @param condition ������
		/// @param to Ŀ��״̬��
		/// @param parameter ����������
		/// @return ���� 1 ����ת��״̬��0 ǿ����ֹת��״̬���������ڵ�ǰ״̬��
		int (*Action)(uint8_t condition, void *parameter, uint8_t from, uint8_t to);
		/// @brief ��̬��
		uint8_t Next;
	} LibMealy_TransitionType;

	/// @brief ״̬�����͡�
	typedef struct
	{
		/// @brief ��ǰ״̬��
		uint8_t CurrentState;
		/// @brief ����״̬��
		uint8_t FinalState;
		/// @brief ״̬������
		uint8_t StateCount;
		/// @brief ����������
		uint8_t ConditionCount;
		/// @brief ת�Ʊ�
		const LibMealy_TransitionType *TransitionTable;
	} LibMealy_MachineType;

	/// @brief ��ʼ��״̬����
	/// @param machine ״̬����
	/// @param transitionTable  ת����
	/// @param stateCount ״̬������
	/// @param conditionCount ����������
	/// @return ���� 1 �ɹ���0 ʧ�ܡ�
	int LibMealy_Init(LibMealy_MachineType *machine, const LibMealy_TransitionType *transitionTable, uint8_t stateCount, uint8_t conditionCount);

	/// @brief ����״̬����
	/// @param machine ״̬����
	/// @param initialState ��ʼ״̬��
	/// @param finalState ����״̬��
	/// @return ���� 1 �ɹ���0 ʧ�ܡ�
	int LibMealy_Start(LibMealy_MachineType *machine, uint8_t initialState, uint8_t finalState);

	/// @brief ֹͣ״̬����
	/// @param machine ״̬����	
	void LibMealy_Stop(LibMealy_MachineType *machine);

	/// @brief ״̬���Ƿ�������״̬��
	/// @param machine ״̬����
	/// @return ���� 1 ��������״̬��0 ���ڷ�����״̬��
	inline int LibMealy_IsFinal(LibMealy_MachineType *machine);

	/// @brief ״̬��ת�ơ�
	/// @param machine ״̬����
	/// @param condition ������
	/// @param parameter ����������
	/// @return ���� 1 �ɹ���0 ʧ�ܡ�
	int LibMealy_Raise(LibMealy_MachineType *machine, uint8_t condition, void *parameter);
#ifdef __cplusplus
}
#endif
#endif
