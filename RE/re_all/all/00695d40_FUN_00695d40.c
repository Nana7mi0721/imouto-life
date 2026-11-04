
void FUN_00695d40(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[0x5e];
  iVar2 = *(int *)(iVar1 + 0x10);
  if (iVar2 == 0) {
    FUN_00695ee0(param_1);
    FUN_00695ff0(param_1);
    if ((char)param_1[0x34] == '\0') {
      (**(code **)param_1[99])(param_1);
      (**(code **)param_1[100])(param_1);
      (**(code **)param_1[0x60])(param_1,0);
    }
    (**(code **)param_1[0x65])(param_1);
    (**(code **)param_1[0x66])(param_1,*(undefined1 *)((int)param_1 + 0xd2));
    (**(code **)param_1[0x61])(param_1,(*(int *)(iVar1 + 0x18) < 2) - 1U & 3);
    (**(code **)param_1[0x5f])(param_1,0);
    if (*(char *)((int)param_1 + 0xd2) == '\0') {
      *(undefined1 *)(iVar1 + 0xc) = 1;
    }
    else {
      *(undefined1 *)(iVar1 + 0xc) = 0;
    }
  }
  else {
    if (iVar2 == 1) {
      FUN_00695ee0(param_1);
      FUN_00695ff0(param_1);
      if ((param_1[0x57] != 0) || (param_1[0x59] == 0)) {
        (**(code **)param_1[0x66])(param_1,1);
        (**(code **)param_1[0x61])(param_1,2);
        *(undefined1 *)(iVar1 + 0xc) = 0;
        goto LAB_00695eb0;
      }
      *(undefined4 *)(iVar1 + 0x10) = 2;
      *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + 1;
    }
    else if (iVar2 != 2) {
      *(undefined4 *)(*param_1 + 0x14) = 0x31;
      (**(code **)*param_1)(param_1);
      goto LAB_00695eb0;
    }
    if (*(char *)((int)param_1 + 0xd2) == '\0') {
      FUN_00695ee0(param_1);
      FUN_00695ff0(param_1);
    }
    (**(code **)param_1[0x66])(param_1,0);
    (**(code **)param_1[0x61])(param_1,2);
    if (*(int *)(iVar1 + 0x1c) == 0) {
      (**(code **)(param_1[0x62] + 4))(param_1);
    }
    (**(code **)(param_1[0x62] + 8))(param_1);
    *(undefined1 *)(iVar1 + 0xc) = 0;
  }
LAB_00695eb0:
  *(bool *)(iVar1 + 0xd) = *(int *)(iVar1 + 0x14) == *(int *)(iVar1 + 0x18) + -1;
  if (param_1[2] != 0) {
    *(int *)(param_1[2] + 0xc) = *(int *)(iVar1 + 0x14);
    *(undefined4 *)(param_1[2] + 0x10) = *(undefined4 *)(iVar1 + 0x18);
  }
  return;
}

