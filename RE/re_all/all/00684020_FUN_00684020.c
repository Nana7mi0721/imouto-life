
void FUN_00684020(int *param_1,undefined4 param_2,uint param_3)

{
  int *piVar1;
  uint uVar2;
  
  piVar1 = param_1;
  if (param_1[5] != 0x65) {
    *(undefined4 *)(*param_1 + 0x14) = 0x15;
    *(int *)(*param_1 + 0x18) = param_1[5];
    (**(code **)*param_1)(param_1);
  }
  if ((uint)piVar1[8] <= (uint)piVar1[0x3e]) {
    *(undefined4 *)(*piVar1 + 0x14) = 0x7e;
    (**(code **)(*piVar1 + 4))(piVar1,0xffffffff);
  }
  if (piVar1[2] != 0) {
    *(int *)(piVar1[2] + 4) = piVar1[0x3e];
    *(int *)(piVar1[2] + 8) = piVar1[8];
    (**(code **)piVar1[2])(piVar1);
  }
  if (*(char *)(piVar1[0x5e] + 0xc) != '\0') {
    (**(code **)(piVar1[0x5e] + 4))(piVar1);
  }
  uVar2 = param_3;
  if ((uint)(piVar1[8] - piVar1[0x3e]) < param_3) {
    uVar2 = piVar1[8] - piVar1[0x3e];
  }
  param_1 = (int *)0x0;
  (**(code **)(piVar1[0x5f] + 4))(piVar1,param_2,&param_1,uVar2);
  piVar1[0x3e] = piVar1[0x3e] + (int)param_1;
  return;
}

