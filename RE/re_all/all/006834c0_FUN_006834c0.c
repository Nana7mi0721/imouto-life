
void FUN_006834c0(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  param_1[1] = 0;
  if (param_2 != 0x5a) {
    *(undefined4 *)(*param_1 + 0x14) = 0xd;
    *(undefined4 *)(*param_1 + 0x18) = 0x5a;
    *(int *)(*param_1 + 0x1c) = param_2;
    (**(code **)*param_1)(param_1);
  }
  if (param_3 != 0x1c8) {
    *(undefined4 *)(*param_1 + 0x14) = 0x16;
    *(undefined4 *)(*param_1 + 0x18) = 0x1c8;
    *(int *)(*param_1 + 0x1c) = param_3;
    (**(code **)*param_1)(param_1);
  }
  iVar4 = *param_1;
  iVar1 = param_1[3];
  piVar2 = param_1;
  for (iVar3 = 0x72; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar2 = 0;
    piVar2 = piVar2 + 1;
  }
  *param_1 = iVar4;
  param_1[3] = iVar1;
  *(undefined1 *)(param_1 + 4) = 1;
  FUN_00685750(param_1);
  param_1[2] = 0;
  param_1[6] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  iVar4 = 4;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  piVar2 = param_1 + 0x2c;
  do {
    piVar2[-4] = 0;
    *piVar2 = 0;
    piVar2 = piVar2 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  param_1[0x45] = 0;
  FUN_006810d0(param_1);
  FUN_00684da0(param_1);
  param_1[5] = 200;
  return;
}

