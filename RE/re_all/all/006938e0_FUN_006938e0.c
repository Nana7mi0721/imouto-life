
void FUN_006938e0(int *param_1,char param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  
  if (param_2 != '\0') {
    *(undefined4 *)(*param_1 + 0x14) = 3;
    (**(code **)*param_1)(param_1);
  }
  puVar1 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0x40);
  param_1[0x60] = (int)puVar1;
  *puVar1 = &LAB_00693990;
  if (*(char *)(param_1[100] + 8) != '\0') {
    puVar1[1] = &LAB_00693bb0;
    FUN_00693d80(param_1);
    return;
  }
  puVar1[1] = &LAB_006939e0;
  iVar3 = 0;
  if (0 < param_1[0x13]) {
    piVar4 = (int *)(param_1[0x15] + 8);
    puVar1 = puVar1 + 2;
    do {
      uVar2 = (**(code **)(param_1[1] + 8))
                        (param_1,1,(piVar4[5] * param_1[0x42] * param_1[0x40]) / *piVar4,
                         param_1[0x41]);
      *puVar1 = uVar2;
      iVar3 = iVar3 + 1;
      puVar1 = puVar1 + 1;
      piVar4 = piVar4 + 0x16;
    } while (iVar3 < param_1[0x13]);
  }
  return;
}

