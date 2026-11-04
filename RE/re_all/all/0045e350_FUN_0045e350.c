
undefined4 __fastcall FUN_0045e350(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int local_18;
  int local_14;
  int local_10;
  int local_8;
  
  puVar1 = (undefined4 *)FUN_004ce990(1);
  local_8 = FUN_00487080(*puVar1);
  if (local_8 < 500000) {
    iVar2 = FUN_0046f600(local_8);
    if (iVar2 != -1) {
      uVar3 = FUN_0046f600(local_8);
      FUN_004d2a00(uVar3);
      iVar2 = FUN_004cf130();
      puVar1 = (undefined4 *)FUN_004ce990(2);
      iVar4 = FUN_00487080(*puVar1);
      if (iVar4 < iVar2) {
        uVar5 = 0xffffffff;
        uVar3 = FUN_0046f600(local_8);
        FUN_004d2a00(uVar3);
        FUN_004799d0(uVar5);
      }
    }
  }
  else {
    if (599999 < local_8) {
      if (*(int *)(param_1 + 0x18) + -0x92824 + local_8 < 0) {
        local_10 = 0;
      }
      else {
        local_10 = *(int *)(param_1 + 0x18) + -0x92824 + local_8;
      }
      iVar2 = FUN_004cfab0();
      if (local_10 < iVar2 + -1) {
        if (*(int *)(param_1 + 0x18) + -0x92824 + local_8 < 0) {
          local_14 = 0;
        }
        else {
          local_14 = *(int *)(param_1 + 0x18) + -0x92824 + local_8;
        }
        local_18 = local_14;
      }
      else {
        local_18 = FUN_004cfab0();
        local_18 = local_18 + -1;
      }
      local_8 = local_18 + 500000;
    }
    DAT_00a14058 = local_8 % 500000;
  }
  return 1;
}

