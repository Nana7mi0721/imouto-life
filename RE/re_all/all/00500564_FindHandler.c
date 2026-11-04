
/* Library Function - Single Match
    void __cdecl FindHandler(struct EHExceptionRecord *,struct EHRegistrationNode *,struct _CONTEXT
   *,void *,struct _s_FuncInfo const *,unsigned char,int,struct EHRegistrationNode *)
   
   Library: Visual Studio 2003 Release */

void __cdecl
FindHandler(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,void *param_4,
           _s_FuncInfo *param_5,uchar param_6,int param_7,EHRegistrationNode *param_8)

{
  int iVar1;
  _ptiddata p_Var2;
  int iVar3;
  _s_TryBlockMapEntry *p_Var4;
  int iVar5;
  int unaff_EBX;
  _s_TryBlockMapEntry *unaff_ESI;
  _s_CatchableType *unaff_EDI;
  EHRegistrationNode *pEVar6;
  uint in_stack_ffffffdc;
  uint local_20 [2];
  int local_18;
  int *local_14;
  uint local_10;
  _s_TryBlockMapEntry *local_c;
  undefined1 local_5;
  
  iVar1 = *(int *)(param_2 + 8);
  local_5 = 0;
  if ((iVar1 < -1) || (param_5->maxState <= iVar1)) {
    _inconsistency();
  }
  if (*(int *)param_1 == -0x1f928c9d) {
    if ((*(int *)(param_1 + 0x10) == 3) &&
       (((*(int *)(param_1 + 0x14) == 0x19930520 || (*(int *)(param_1 + 0x14) == 0x19930521)) &&
        (*(int *)(param_1 + 0x1c) == 0)))) {
      p_Var2 = __getptd();
      if (p_Var2->_unexpected == (void *)0x0) {
        return;
      }
      p_Var2 = __getptd();
      param_1 = p_Var2->_unexpected;
      p_Var2 = __getptd();
      param_3 = p_Var2->_translator;
      local_5 = 1;
      iVar3 = _ValidateRead(param_1,1);
      if (iVar3 == 0) {
        _inconsistency();
      }
      if (*(int *)param_1 != -0x1f928c9d) goto LAB_0050073d;
      if (((*(int *)(param_1 + 0x10) == 3) &&
          ((*(int *)(param_1 + 0x14) == 0x19930520 || (*(int *)(param_1 + 0x14) == 0x19930521)))) &&
         (*(int *)(param_1 + 0x1c) == 0)) {
        _inconsistency();
      }
    }
    if (((*(int *)param_1 == -0x1f928c9d) && (*(int *)(param_1 + 0x10) == 3)) &&
       ((*(int *)(param_1 + 0x14) == 0x19930520 || (*(int *)(param_1 + 0x14) == 0x19930521)))) {
      p_Var4 = _GetRangeOfTrysToCheck(param_5,param_7,iVar1,&local_10,local_20 + -1);
      do {
        local_c = p_Var4;
        if (in_stack_ffffffdc <= local_10) {
          if (param_6 == '\0') {
            return;
          }
          ___DestructExceptionObject(param_1,1);
          return;
        }
        if ((p_Var4->tryLow <= iVar1) && (iVar1 <= p_Var4->tryHigh)) {
          for (iVar3 = p_Var4->nCatches; 0 < iVar3; iVar3 = iVar3 + -1) {
            local_14 = *(int **)(*(int *)(param_1 + 0x1c) + 0xc);
            local_18 = *local_14;
            if (0 < local_18) {
              do {
                local_14 = local_14 + 1;
                pEVar6 = (EHRegistrationNode *)*local_14;
                iVar5 = TypeMatch(*(_s_HandlerType **)(param_1 + 0x1c),unaff_EDI,
                                  (_s_ThrowInfo *)unaff_ESI);
                p_Var4 = local_c;
                if (iVar5 != 0) {
                  CatchIt(param_1,(EHRegistrationNode *)param_3,param_4,param_5,
                          (_s_FuncInfo *)param_7,(_s_HandlerType *)param_8,unaff_EDI,unaff_ESI,
                          unaff_EBX,pEVar6,(uchar)in_stack_ffffffdc);
                  goto LAB_00500710;
                }
                local_18 = local_18 + -1;
              } while (0 < local_18);
            }
          }
        }
LAB_00500710:
        local_10 = local_10 + 1;
        p_Var4 = p_Var4 + 1;
      } while( true );
    }
  }
LAB_0050073d:
  if (param_6 == '\0') {
    FindHandlerForForeignException(param_1,param_2,param_3,param_4,param_5,iVar1,param_7,param_8);
    return;
  }
  terminate();
  return;
}

