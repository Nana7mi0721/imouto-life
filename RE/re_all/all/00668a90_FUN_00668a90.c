
void FUN_00668a90(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  uVar1 = *(uint *)(param_1 + 0x11c);
  iVar2 = 0;
  iVar6 = 0x18;
  do {
    uVar4 = uVar1 >> ((byte)iVar6 & 0x1f);
    iVar6 = iVar6 + -8;
    uVar5 = uVar4 & 0xff;
    if (((uVar5 < 0x41) || (0x7a < uVar5)) || ((0x5a < uVar5 && (uVar5 < 0x61)))) {
      *(undefined1 *)(iVar2 + param_2) = 0x5b;
      *(char *)(iVar2 + 1 + param_2) = "0123456789ABCDEF"[(int)uVar5 >> 4];
      *(char *)(iVar2 + 2 + param_2) = "0123456789ABCDEF"[uVar4 & 0xf];
      iVar3 = iVar2 + 3;
      *(undefined1 *)(iVar3 + param_2) = 0x5d;
    }
    else {
      *(char *)(iVar2 + param_2) = (char)uVar4;
      iVar3 = iVar2;
    }
    iVar2 = iVar3 + 1;
  } while (-1 < iVar6);
  if (param_3 != 0) {
    iVar6 = 0;
    *(undefined1 *)(iVar2 + param_2) = 0x3a;
    *(undefined1 *)(iVar3 + 2 + param_2) = 0x20;
    iVar2 = iVar3 + 3;
    do {
      if (*(char *)(iVar6 + param_3) == '\0') break;
      *(char *)(iVar2 + param_2) = *(char *)(iVar6 + param_3);
      iVar2 = iVar2 + 1;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 0xc3);
  }
  *(undefined1 *)(iVar2 + param_2) = 0;
  return;
}

