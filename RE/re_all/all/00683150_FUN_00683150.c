
void FUN_00683150(int *param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  code *pcVar3;
  
  iVar1 = param_1[0x6b];
  uVar2 = *(int *)(param_1[1] + 0x30) - 0x14;
  if ((int)uVar2 < (int)param_3) {
    param_3 = uVar2;
  }
  if (param_3 == 0) {
    pcVar3 = FUN_006815f0;
    if ((param_2 == 0xe0) || (param_2 == 0xee)) {
      pcVar3 = (code *)&LAB_00681140;
    }
  }
  else {
    pcVar3 = (code *)&LAB_00683230;
    if (param_2 == 0xe0) {
      if (param_3 < 0xe) {
        *(undefined1 **)(iVar1 + 0x1c) = &LAB_00683230;
        *(undefined4 *)(iVar1 + 0x60) = 0xe;
        return;
      }
      goto LAB_006831fa;
    }
    if (param_2 == 0xee) {
      if (param_3 < 0xc) {
        *(undefined1 **)(iVar1 + 0x54) = &LAB_00683230;
        *(undefined4 *)(iVar1 + 0x98) = 0xc;
        return;
      }
      goto LAB_006831fa;
    }
  }
  if (param_2 == 0xfe) {
    *(code **)(iVar1 + 0x18) = pcVar3;
    *(uint *)(iVar1 + 0x5c) = param_3;
    return;
  }
  if ((param_2 < 0xe0) || (0xef < param_2)) {
    *(undefined4 *)(*param_1 + 0x14) = 0x46;
    *(int *)(*param_1 + 0x18) = param_2;
    (**(code **)*param_1)(param_1);
    return;
  }
LAB_006831fa:
  *(code **)(iVar1 + -0x364 + param_2 * 4) = pcVar3;
  *(uint *)(iVar1 + -800 + param_2 * 4) = param_3;
  return;
}

