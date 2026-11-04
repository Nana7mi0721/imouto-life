
void FUN_006877d0(int *param_1,char param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  
  puVar1 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0x50);
  param_1[0x67] = (int)puVar1;
  *puVar1 = &LAB_00687960;
  if (param_2 != '\0') {
    *(undefined4 *)(*param_1 + 0x14) = 3;
    (**(code **)*param_1)(param_1);
  }
  _param_2 = param_1[0x49];
  if (*(char *)(param_1[0x6e] + 8) != '\0') {
    if (_param_2 < 2) {
      *(undefined4 *)(*param_1 + 0x14) = 0x30;
      (**(code **)*param_1)(param_1);
    }
    FUN_006878b0(param_1);
    _param_2 = param_1[0x49] + 2;
  }
  iVar3 = 0;
  if (0 < param_1[9]) {
    piVar4 = (int *)(param_1[0x31] + 0xc);
    puVar1 = puVar1 + 2;
    do {
      uVar2 = (**(code **)(param_1[1] + 8))
                        (param_1,1,piVar4[6] * piVar4[4],
                         ((piVar4[7] * *piVar4) / param_1[0x49]) * _param_2);
      *puVar1 = uVar2;
      iVar3 = iVar3 + 1;
      puVar1 = puVar1 + 1;
      piVar4 = piVar4 + 0x16;
    } while (iVar3 < param_1[9]);
  }
  return;
}

