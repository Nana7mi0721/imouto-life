
void FUN_0066de40(int param_1)

{
  char cVar1;
  uint uVar2;
  short sVar3;
  short sVar4;
  
  if ((*(byte *)(param_1 + 0x157) & 4) == 0) {
    uVar2 = *(uint *)(param_1 + 0x7c);
    *(uint *)(param_1 + 0x7c) = uVar2 & 0xff7fffff;
    *(uint *)(param_1 + 0x78) = *(uint *)(param_1 + 0x78) & 0xffffdfff;
    if (*(short *)(param_1 + 0x150) == 0) {
      *(uint *)(param_1 + 0x7c) = uVar2 & 0xff7ffe7f;
    }
  }
  uVar2 = *(uint *)(param_1 + 0x7c);
  if ((((uVar2 & 0x100) != 0) && ((uVar2 & 0x1000) != 0)) && ((*(byte *)(param_1 + 0x157) & 2) == 0)
     ) {
    cVar1 = *(char *)(param_1 + 0x158);
    sVar3 = *(short *)(param_1 + 0x170);
    sVar4 = *(short *)(param_1 + 0x1c0);
    if (cVar1 == '\x01') {
      sVar3 = sVar3 * 0xff;
      sVar4 = sVar4 * 0xff;
    }
    else if (cVar1 == '\x02') {
      sVar3 = sVar3 * 0x55;
      sVar4 = sVar4 * 0x55;
    }
    else if (cVar1 == '\x04') {
      sVar3 = sVar3 * 0x11;
      sVar4 = sVar4 * 0x11;
    }
    *(short *)(param_1 + 0x16e) = sVar3;
    *(short *)(param_1 + 0x16c) = sVar3;
    *(short *)(param_1 + 0x16a) = sVar3;
    if ((uVar2 & 0x2000000) == 0) {
      *(short *)(param_1 + 0x1be) = sVar4;
      *(short *)(param_1 + 0x1bc) = sVar4;
      *(short *)(param_1 + 0x1ba) = sVar4;
    }
  }
  return;
}

