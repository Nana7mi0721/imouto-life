
void __thiscall FUN_0047c5e0(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined1 local_18 [4];
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  int local_c;
  undefined4 local_8;
  
  if (((param_3 != 0) &&
      (((param_2 != 0 || (*(int *)(param_1 + 0x60) == 0)) || (param_3 != *(int *)(param_1 + 0x60))))
      ) && (((param_2 != 1 || (*(int *)(param_1 + 0x68) == 0)) ||
            (param_3 != *(int *)(param_1 + 0x68))))) {
    local_c = 0;
    while (iVar2 = FUN_004717c0(param_2 + 1), local_c < iVar2) {
      piVar3 = (int *)FUN_004cc020(&local_c);
      if (*piVar3 == param_3) {
        uVar4 = FUN_004cc020(&local_c);
        puVar5 = (undefined4 *)FUN_004cc020(uVar4);
        *puVar5 = 0;
        puVar5 = (undefined4 *)FUN_004cc020(&local_c);
        *puVar5 = 0;
        FUN_0055f370(param_3);
        FUN_00515700(param_3,0);
        break;
      }
      local_c = local_c + 1;
    }
    FUN_004cc870(&local_8);
    while( true ) {
      uVar4 = FUN_004ce060(local_10);
      cVar1 = const_iterator__operator__(uVar4);
      if (cVar1 == '\0') break;
      iVar2 = FUN_004d07e0();
      if (*(int *)(iVar2 + 0x1c) == param_3) {
        FUN_004e7cd0(local_14,local_8);
        return;
      }
      FUN_004e9550(local_18,0);
    }
  }
  return;
}

