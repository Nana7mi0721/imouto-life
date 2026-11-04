
undefined4 FUN_0064ded6(void)

{
  undefined1 *in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar3 = 0x100;
  do {
    iVar4 = 0x100;
    iVar1 = 0x7f;
    do {
      *in_EAX = (char)(iVar1 / 0xff);
      in_EAX = in_EAX + 1;
      iVar4 = iVar4 + -1;
      iVar1 = iVar1 + iVar2;
    } while (iVar4 != 0);
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return 1;
}

