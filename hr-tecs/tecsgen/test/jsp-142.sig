
namespace toppers {
	typedef	unsigned int	UW;
	typedef signed int INT;
	typedef unsigned int UINT;
	typedef INT ER;
	typedef INT ER_BOOL;
	typedef INT ER_ID;
	typedef INT ER_UINT;
	typedef INT ID;
	typedef INT PRI;
	typedef INT TMO;
	typedef UINT RELTIM;
	typedef	void	*VP;		
	typedef bool BOOL;
	/* #define _bool_ int */
	typedef UINT MODE;
	/* typedef _vp_int_ VP_INT */
	typedef VP VP_INT;
	typedef	UW		SYSTIM;		
	
	/**/
	/* kernel.hで定義 */
	typedef UINT TEXPTN;
	typedef UINT FLGPTN;

	typedef	struct t_msg {	/* メールボックスのメッセージヘッダ */
		struct t_msg	*next;
	} T_MSG;
	
	typedef	struct t_msg_pri {		/* 優先度付きメッセージヘッダ */
		T_MSG		msgque;		/* メッセージヘッダ */
		PRI		msgpri;		/* メッセージ優先度 */
	} T_MSG_PRI;
	
	signature toppser {
		ER act_tsk ( [in] ID tskid );
		ER iact_tsk ( [in] ID tskid );
		ER_UINT can_act ( [in] ID tskid );
		void ext_tsk ( void );
		ER ter_tsk ( [in] ID tskid );
		ER chg_pri ( [in] ID tskid , [in] PRI tskpri );
		ER get_pri ( [in] ID tskid , [out] PRI * p_tskpri );
		ER slp_tsk ( void );
		ER tslp_tsk ( [in] TMO tmout );
		ER wup_tsk ( [in] ID tskid );
		ER iwup_tsk ( [in] ID tskid );
		ER_UINT can_wup ( [in] ID tskid );
		ER rel_wai ( [in] ID tskid );
		ER irel_wai ( [in] ID tskid );
		ER sus_tsk ( [in] ID tskid );
		ER rsm_tsk ( [in] ID tskid );
		ER frsm_tsk ( [in] ID tskid );
		ER dly_tsk ( [in] RELTIM dlytim );
		ER ras_tex ( [in] ID tskid , [in] TEXPTN rasptn );
		ER iras_tex ( [in] ID tskid , [in] TEXPTN rasptn );
		ER dis_tex ( void );
		ER ena_tex ( void );
		BOOL sns_tex ( void );
		ER sig_sem ( [in] ID semid );
		ER isig_sem ( [in] ID semid );
		ER wai_sem ( [in] ID semid );
		ER pol_sem ( [in] ID semid );
		ER twai_sem ( [in] ID semid , [in] TMO tmout );
		ER set_flg ( [in] ID flgid , [in] FLGPTN setptn );
		ER iset_flg ( [in] ID flgid , [in] FLGPTN setptn );
		ER clr_flg ( [in] ID flgid , [in] FLGPTN clrptn );
		ER wai_flg ( [in] ID flgid , [in] FLGPTN waiptn , [in] MODE wfmode , [out] FLGPTN * p_flgptn );
		ER pol_flg ( [in] ID flgid , [in] FLGPTN waiptn , [in] MODE wfmode , [out] FLGPTN * p_flgptn );
		ER twai_flg ( [in] ID flgid , [in] FLGPTN waiptn , [in] MODE wfmode , [out] FLGPTN * p_flgptn , [in] TMO tmout );
		ER snd_dtq ( [in] ID dtqid , [in] VP_INT data );
		ER psnd_dtq ( [in] ID dtqid , [in] VP_INT data );
		ER ipsnd_dtq ( [in] ID dtqid , [in] VP_INT data );
		ER tsnd_dtq ( [in] ID dtqid , [in] VP_INT data , [in] TMO tmout );
		ER fsnd_dtq ( [in] ID dtqid , [in] VP_INT data );
		ER ifsnd_dtq ( [in] ID dtqid , [in] VP_INT data );
		ER rcv_dtq ( [in] ID dtqid , [out] VP_INT *p_data );
		ER prcv_dtq ( [in] ID dtqid , [out] VP_INT *p_data );
		ER trcv_dtq ( [in] ID dtqid , [out] VP_INT *p_data , [in] TMO tmout );
		ER snd_mbx ( [in] ID mbxid , [send(sigAlloc)] T_MSG * pk_msg );
		ER rcv_mbx ( [in] ID mbxid , [receive(sigAlloc)] T_MSG * * ppk_msg );
		ER prcv_mbx ( [in] ID mbxid , [receive(sigAlloc)] T_MSG * * ppk_msg );
		ER trcv_mbx ( [in] ID mbxid , [receive(sigAlloc)] T_MSG * * ppk_msg , [in] TMO tmout );
		ER get_mpf  ( [in] ID mpfid , [receive(rel_mpf)] VP * p_blk );
		ER pget_mpf ( [in] ID mpfid , [receive(rel_mpf)] VP * p_blk );
		ER tget_mpf ( [in] ID mpfid , [receive(rel_mpf)] VP * p_blk , [in] TMO tmout );
		ER rel_mpf ( [in] ID mpfid , [send(rel_mpf)] VP *p_blk );
		ER set_tim ( [in] SYSTIM * p_systim );
		ER get_tim ( [out] SYSTIM * p_systim );
		ER isig_tim ( void );
		ER sta_cyc ( [in] ID cycid );
		ER stp_cyc ( [in] ID cycid );
		ER rot_rdq ( [in] PRI tskpri );
		ER irot_rdq ( [in] PRI tskpri );
		ER get_tid ( [out] ID * p_tskid );
		ER iget_tid ( [out] ID * p_tskid );
		ER loc_cpu ( void );
		ER iloc_cpu ( void );
		ER unl_cpu ( void );
		ER iunl_cpu ( void );
		ER dis_dsp ( void );
		ER ena_dsp ( void );
		BOOL sns_ctx ( void );
		BOOL sns_loc ( void );
		BOOL sns_dsp ( void );
		BOOL sns_dpn ( void );
/**/		
		BOOL vxsns_ctx ( [in] VP p_excinf );
		BOOL vxsns_loc ( [in] VP p_excinf );
		BOOL vxsns_dsp ( [in] VP p_excinf );
		BOOL vxsns_dpn ( [in] VP p_excinf );
		BOOL vxsns_tex ( [in] VP p_excinf );
		BOOL vsns_ini ( void );
		
	};
};

		
