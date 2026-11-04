
void __thiscall FUN_005d8a70(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  bool bVar5;
  int in_EAX;
  
  *(int *)(param_1 + 100) = *(int *)(param_1 + 100) + -1;
  piVar1 = (int *)(*(int *)(in_EAX + 0x44) + 0x18);
  *piVar1 = *piVar1 + -1;
  *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
  *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) - *(int *)(in_EAX + 0x20);
  *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + *(int *)(in_EAX + 0x20);
  *(byte *)(in_EAX + 0x16) = *(byte *)(in_EAX + 0x16) & 0xfb;
  bVar5 = false;
  if (*(int *)(in_EAX + 0x38) == 0) {
    *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(in_EAX + 0x3c);
  }
  else {
    *(undefined4 *)(*(int *)(in_EAX + 0x38) + 0x3c) = *(undefined4 *)(in_EAX + 0x3c);
  }
  if (*(int *)(in_EAX + 0x3c) == 0) {
    *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(in_EAX + 0x38);
  }
  else {
    *(undefined4 *)(*(int *)(in_EAX + 0x3c) + 0x38) = *(undefined4 *)(in_EAX + 0x38);
  }
  *(undefined4 *)(in_EAX + 0x38) = 0;
  *(undefined4 *)(in_EAX + 0x3c) = 0;
  if ((((param_2 == 0) && ((*(byte *)(in_EAX + 0x16) & 0x10) != 0)) &&
      (iVar2 = *(int *)(in_EAX + 0x30), iVar2 != 0)) && ((*(byte *)(iVar2 + 0x16) & 4) == 0)) {
    if (*(int *)(param_1 + 0x1c) == 1) {
      FUN_005d6ce0();
    }
    *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + *(int *)(in_EAX + 0x20);
    iVar3 = *(int *)(in_EAX + 0x34);
    *(int *)(iVar2 + 0x34) = iVar3;
    if (iVar3 == 0) {
      *(int *)(param_1 + 0x60) = iVar2;
    }
    else {
      *(int *)(iVar3 + 0x30) = iVar2;
    }
    if ((*(byte *)(in_EAX + 0x16) & 8) == 0) {
      *(byte *)(iVar2 + 0x16) = *(byte *)(iVar2 + 0x16) & 0xf7;
    }
    else {
      *(byte *)(iVar2 + 0x16) = *(byte *)(iVar2 + 0x16) | 8;
    }
    if (*(int *)(param_1 + 0x2c) != 0) {
      FUN_005d6ab0();
    }
    *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + -1;
    bVar5 = true;
    in_EAX = iVar2;
  }
  if ((((*(byte *)(in_EAX + 0x16) & 8) != 0) && (iVar2 = *(int *)(in_EAX + 0x34), iVar2 != 0)) &&
     ((*(byte *)(iVar2 + 0x16) & 4) == 0)) {
    if (*(int *)(param_1 + 0x1c) == 1) {
      FUN_005d6ce0();
    }
    *(int *)(in_EAX + 0x20) = *(int *)(in_EAX + 0x20) + *(int *)(iVar2 + 0x20);
    iVar3 = *(int *)(iVar2 + 0x34);
    *(int *)(in_EAX + 0x34) = iVar3;
    if (iVar3 == 0) {
      *(int *)(param_1 + 0x60) = in_EAX;
    }
    else {
      *(int *)(iVar3 + 0x30) = in_EAX;
    }
    if (*(int *)(param_1 + 0x1c) == 0) {
      iVar3 = *(int *)(iVar2 + 0x3c);
      *(int *)(in_EAX + 0x3c) = iVar3;
      if (iVar3 == 0) {
        *(int *)(param_1 + 0x231c) = in_EAX;
      }
      else {
        *(int *)(iVar3 + 0x38) = in_EAX;
      }
      if (!bVar5) {
        iVar3 = *(int *)(iVar2 + 0x38);
        *(int *)(in_EAX + 0x38) = iVar3;
        if (iVar3 == 0) {
          *(int *)(param_1 + 0x2318) = in_EAX;
        }
        else {
          *(int *)(iVar3 + 0x3c) = in_EAX;
        }
      }
    }
    if ((*(byte *)(iVar2 + 0x16) & 8) == 0) {
      *(byte *)(in_EAX + 0x16) = *(byte *)(in_EAX + 0x16) & 0xf7;
    }
    else {
      *(byte *)(in_EAX + 0x16) = *(byte *)(in_EAX + 0x16) | 8;
    }
    if (*(int *)(param_1 + 0x2c) != 0) {
      FUN_005d6ab0();
    }
    *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + -1;
    bVar5 = true;
  }
  if (*(int *)(param_1 + 0x1c) == 0) {
    if (!bVar5) {
      for (iVar2 = *(int *)(in_EAX + 0x30); (iVar2 != 0 && ((*(byte *)(iVar2 + 0x16) & 4) != 0));
          iVar2 = *(int *)(iVar2 + 0x30)) {
      }
      *(int *)(in_EAX + 0x38) = iVar2;
      if (iVar2 == 0) {
        *(undefined4 *)(in_EAX + 0x3c) = *(undefined4 *)(param_1 + 0x2318);
        *(int *)(param_1 + 0x2318) = in_EAX;
      }
      else {
        *(undefined4 *)(in_EAX + 0x3c) = *(undefined4 *)(iVar2 + 0x3c);
        *(int *)(iVar2 + 0x3c) = in_EAX;
      }
      if (*(int *)(in_EAX + 0x3c) == 0) {
        *(int *)(param_1 + 0x231c) = in_EAX;
      }
      else {
        *(int *)(*(int *)(in_EAX + 0x3c) + 0x38) = in_EAX;
      }
    }
  }
  else if (*(int *)(param_1 + 0x1c) == 1) {
    FUN_005d6c20();
  }
  puVar4 = *(undefined4 **)(in_EAX + 0x44);
  if (((puVar4[6] == 0) && (param_2 == 0)) && ((*(byte *)(puVar4 + 10) & 1) != 0)) {
    FUN_005d8470(param_1,*puVar4);
  }
  return;
}

