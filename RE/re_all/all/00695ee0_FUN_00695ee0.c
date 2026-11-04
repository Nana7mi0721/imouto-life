
void FUN_00695ee0(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  
  iVar4 = param_1[0x33];
  if (iVar4 == 0) {
    if (4 < param_1[0x13]) {
      *(undefined4 *)(*param_1 + 0x14) = 0x1b;
      *(int *)(*param_1 + 0x18) = param_1[0x13];
      *(undefined4 *)(*param_1 + 0x1c) = 4;
      (**(code **)*param_1)(param_1);
    }
    iVar4 = 0;
    param_1[0x45] = param_1[0x13];
    if (0 < param_1[0x13]) {
      iVar2 = 0;
      piVar1 = param_1 + 0x46;
      do {
        iVar4 = iVar4 + 1;
        *piVar1 = param_1[0x15] + iVar2;
        piVar1 = piVar1 + 1;
        iVar2 = iVar2 + 0x58;
      } while (iVar4 < param_1[0x13]);
    }
  }
  else {
    iVar2 = *(int *)(param_1[0x5e] + 0x1c);
    param_1[0x45] = *(int *)(iVar4 + iVar2 * 0x24);
    piVar1 = (int *)(iVar4 + iVar2 * 0x24);
    iVar3 = 0;
    if (0 < *(int *)(iVar4 + iVar2 * 0x24)) {
      piVar5 = param_1 + 0x46;
      piVar6 = piVar1;
      do {
        piVar6 = piVar6 + 1;
        iVar3 = iVar3 + 1;
        *piVar5 = param_1[0x15] + *piVar6 * 0x58;
        piVar5 = piVar5 + 1;
      } while (iVar3 < *piVar1);
    }
    if ((char)param_1[0x3f] != '\0') {
      param_1[0x57] = piVar1[5];
      param_1[0x58] = piVar1[6];
      param_1[0x59] = piVar1[7];
      param_1[0x5a] = piVar1[8];
      return;
    }
  }
  param_1[0x57] = 0;
  param_1[0x59] = 0;
  param_1[0x5a] = 0;
  param_1[0x58] = param_1[0x5b] * param_1[0x5b] + -1;
  return;
}

