
void FUN_00686670(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined1 uVar4;
  int iVar5;
  
  piVar3 = param_1;
  iVar2 = param_1[0x66];
  FUN_00686380(param_1);
  FUN_00686840(param_1);
  *(undefined4 *)(iVar2 + 0xc) = 0;
  uVar4 = FUN_00686580(param_1);
  *(undefined1 *)(iVar2 + 0x10) = uVar4;
  *(undefined4 *)(iVar2 + 0x14) = 0;
  *(undefined4 *)(iVar2 + 0x18) = 0;
  if ((*(char *)((int)param_1 + 0x4a) == '\0') || ((char)param_1[0x10] == '\0')) {
    *(undefined1 *)(param_1 + 0x16) = 0;
    *(undefined1 *)((int)param_1 + 0x59) = 0;
    *(undefined1 *)((int)param_1 + 0x5a) = 0;
  }
  if (*(char *)((int)param_1 + 0x4a) != '\0') {
    if (*(char *)((int)param_1 + 0x41) != '\0') {
      *(undefined4 *)(*param_1 + 0x14) = 0x30;
      (**(code **)*param_1)(param_1);
    }
    if (param_1[0x19] == 3) {
      if (param_1[0x1d] == 0) {
        if ((char)param_1[0x14] == '\0') {
          *(undefined1 *)(param_1 + 0x16) = 1;
        }
        else {
          *(undefined1 *)((int)param_1 + 0x5a) = 1;
        }
      }
      else {
        *(undefined1 *)((int)param_1 + 0x59) = 1;
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x16) = 1;
      *(undefined1 *)((int)param_1 + 0x59) = 0;
      *(undefined1 *)((int)param_1 + 0x5a) = 0;
      param_1[0x1d] = 0;
    }
    if ((char)param_1[0x16] != '\0') {
      FUN_0068ef30(param_1);
      *(int *)(iVar2 + 0x14) = param_1[0x70];
    }
    if ((*(char *)((int)param_1 + 0x5a) != '\0') || (*(char *)((int)param_1 + 0x59) != '\0')) {
      FUN_0068db40(param_1);
      *(int *)(iVar2 + 0x18) = param_1[0x70];
    }
  }
  if (*(char *)((int)param_1 + 0x41) == '\0') {
    if (*(char *)(iVar2 + 0x10) == '\0') {
      FUN_0068caf0(param_1);
      FUN_0068c600(param_1);
    }
    else {
      FUN_0068d550();
    }
    FUN_0068c290(param_1,*(undefined1 *)((int)param_1 + 0x5a));
  }
  FUN_0068bd80(param_1);
  if (*(char *)((int)param_1 + 0xca) == '\0') {
    FUN_00688e80(param_1);
  }
  else {
    FUN_0068aca0();
  }
  if ((*(char *)(param_1[0x6a] + 0x10) != '\0') ||
     (piVar1 = param_1 + 0x10, param_1 = (int *)0x0, (char)*piVar1 != '\0')) {
    param_1 = (int *)0x1;
  }
  FUN_00687ec0(piVar3,param_1);
  if (*(char *)((int)piVar3 + 0x41) == '\0') {
    FUN_006877d0(piVar3,0);
  }
  (**(code **)(piVar3[1] + 0x18))(piVar3);
  (**(code **)(piVar3[0x6a] + 8))(piVar3);
  if (((piVar3[2] != 0) && ((char)piVar3[0x10] == '\0')) && (*(char *)(piVar3[0x6a] + 0x10) != '\0')
     ) {
    iVar5 = piVar3[9];
    if (*(char *)((int)piVar3 + 0xc9) != '\0') {
      iVar5 = iVar5 * 3 + 2;
    }
    *(undefined4 *)(piVar3[2] + 4) = 0;
    *(int *)(piVar3[2] + 8) = piVar3[0x4a] * iVar5;
    *(undefined4 *)(piVar3[2] + 0xc) = 0;
    *(uint *)(piVar3[2] + 0x10) = (*(char *)((int)piVar3 + 0x5a) != '\0') + 2;
    *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;
  }
  return;
}

