
void FUN_005d6970(int param_1,int param_2,int param_3)

{
  int in_EAX;
  char *pcVar1;
  int iVar2;
  int unaff_EBX;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  
  *unaff_ESI = 0x4d454d44;
  if (in_EAX == 0) {
    *(byte *)((int)unaff_ESI + 0x16) = *(byte *)((int)unaff_ESI + 0x16) & 0xfb;
  }
  else {
    *(byte *)((int)unaff_ESI + 0x16) = *(byte *)((int)unaff_ESI + 0x16) | 4;
  }
  if (param_3 == 0) {
    *(byte *)((int)unaff_ESI + 0x16) = *(byte *)((int)unaff_ESI + 0x16) & 0xdf;
  }
  else {
    *(byte *)((int)unaff_ESI + 0x16) = *(byte *)((int)unaff_ESI + 0x16) | 0x20;
  }
  if (param_1 != 0) {
    if (unaff_EBX == 0) {
      pcVar1 = "NoName";
      if (in_EAX == 0) {
        pcVar1 = "Free";
      }
    }
    else {
      iVar2 = FUN_005773c0(0x7ffd);
      if (iVar2 < 0x11) {
        iVar2 = 0;
      }
      else {
        iVar2 = iVar2 + -0x11;
      }
      pcVar1 = (char *)(iVar2 + unaff_EBX);
    }
    FUN_00576e80(0x7ffd,unaff_ESI + 1,pcVar1);
    if (param_2 < 0) {
      param_2 = 0;
    }
    *(short *)((int)unaff_ESI + 0x1e) = (short)param_2;
    *(byte *)((int)unaff_ESI + 0x16) =
         (byte)((uint)param_2 >> 0x10) | *(byte *)((int)unaff_ESI + 0x16) & 0xfc;
  }
  unaff_ESI[0x10] = unaff_EDI;
  *(undefined1 *)((int)unaff_ESI + 0x19) = *(undefined1 *)(unaff_EDI + 0x26);
  *(undefined2 *)((int)unaff_ESI + 0x1a) = *(undefined2 *)(unaff_EDI + 0x24);
  *(int *)(unaff_EDI + 0x24) = *(int *)(unaff_EDI + 0x24) + 1;
  if (*(uint *)(unaff_EDI + 0x24) < 0x1000000) {
    *(undefined2 *)(unaff_ESI + 7) = *(undefined2 *)(unaff_EDI + 0x28);
    return;
  }
  *(undefined4 *)(unaff_EDI + 0x24) = 0;
  *(undefined2 *)(unaff_ESI + 7) = *(undefined2 *)(unaff_EDI + 0x28);
  return;
}

