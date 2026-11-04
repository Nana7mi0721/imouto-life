
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint __thiscall FUN_004bf9b0(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint *puVar3;
  int local_8;
  
  if (*(int *)(param_1 + 0x1658) != -1) {
    for (local_8 = 2; -1 < local_8; local_8 = local_8 + -1) {
      uVar2 = FUN_0047a4d0(param_2,param_3 + 1,local_8);
      puVar3 = (uint *)FUN_004ce990(uVar2);
      uVar1 = *puVar3;
      uVar2 = FUN_0047a4d0(param_2 + 1,param_3 + 1,local_8);
      puVar3 = (uint *)FUN_004ce990(uVar2);
      if (((uVar1 & 0x40) == 0x40) && ((*puVar3 & 0x40) == 0x40)) {
        return 1;
      }
      param_1 = 0;
    }
  }
  return param_1 & 0xffffff00;
}

