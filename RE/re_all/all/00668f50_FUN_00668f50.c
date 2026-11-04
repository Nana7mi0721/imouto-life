
void FUN_00668f50(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((*(uint *)(param_1 + 0x11c) & 0x20000000) == 0) {
    if ((*(uint *)(param_1 + 0x78) & 0x800) != 0) {
      return;
    }
  }
  else if ((*(uint *)(param_1 + 0x78) & 0x300) == 0x300) {
    return;
  }
  if (param_3 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x140);
    do {
      iVar2 = param_3;
      if (param_3 == 0) {
        iVar2 = -1;
      }
      uVar1 = FUN_0067c560(uVar1,param_2,iVar2);
      param_2 = param_2 + iVar2;
      param_3 = param_3 - iVar2;
    } while (param_3 != 0);
    *(undefined4 *)(param_1 + 0x140) = uVar1;
  }
  return;
}

