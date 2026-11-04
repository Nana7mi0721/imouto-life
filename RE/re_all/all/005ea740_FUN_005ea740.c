
undefined4 FUN_005ea740(void)

{
  int *in_EAX;
  int iVar1;
  
  iVar1 = *in_EAX;
  if (in_EAX[0x11] == 0) {
    if (in_EAX[0xe] == 0) {
      if (*(int *)(iVar1 + 0x50) == 0) {
        iVar1 = *(int *)(iVar1 + 0x48);
      }
      else {
        iVar1 = *(int *)(iVar1 + 0x54);
      }
    }
    else {
      iVar1 = in_EAX[0xf];
    }
  }
  else {
    iVar1 = in_EAX[0x12];
  }
  iVar1 = FUN_00519300(iVar1,0);
  if (iVar1 == 0) {
    return 0;
  }
  return *(undefined4 *)(**(int **)(iVar1 + 0x100) + 8);
}

