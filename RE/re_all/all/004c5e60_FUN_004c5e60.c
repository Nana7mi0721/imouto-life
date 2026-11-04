
void __thiscall FUN_004c5e60(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;
  
  local_8 = 0;
  do {
    iVar1 = FUN_004d3180(param_1);
    if (iVar1 <= local_8) {
      return;
    }
    if (param_2 == 0) {
      iVar1 = FUN_004d31e0(local_8);
      if (*(int *)(iVar1 + 0x26c) < 0) goto LAB_004c5ed9;
      iVar1 = FUN_004d31e0(local_8);
      if (99999 < *(int *)(iVar1 + 0x26c)) goto LAB_004c5ed9;
      uVar2 = 1;
      FUN_004d31e0(local_8);
      FUN_00488310(uVar2);
    }
    else {
LAB_004c5ed9:
      if (param_2 == 1) {
        iVar1 = FUN_004d31e0(local_8);
        if (99999 < *(int *)(iVar1 + 0x26c)) {
          uVar2 = 1;
          FUN_004d31e0(local_8);
          FUN_00488310(uVar2);
          goto LAB_004c5e72;
        }
      }
      if (param_2 == -1) {
        iVar1 = FUN_004d31e0(local_8);
        if (*(int *)(iVar1 + 0x26c) < 0) {
          iVar1 = FUN_004d31e0(local_8);
          if (-100000 < *(int *)(iVar1 + 0x26c)) {
            uVar2 = 1;
            FUN_004d31e0(local_8);
            FUN_00488310(uVar2);
            goto LAB_004c5e72;
          }
        }
      }
      if (param_2 == -2) {
        iVar1 = FUN_004d31e0(local_8);
        if (*(int *)(iVar1 + 0x26c) < -99999) {
          uVar2 = 1;
          FUN_004d31e0(local_8);
          FUN_00488310(uVar2);
        }
      }
    }
LAB_004c5e72:
    local_8 = local_8 + 1;
  } while( true );
}

