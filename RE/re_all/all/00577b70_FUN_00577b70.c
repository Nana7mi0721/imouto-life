
int FUN_00577b70(void)

{
  uint uVar1;
  int in_EAX;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint *unaff_EDI;
  byte local_400 [1024];
  
  uVar4 = 0;
  puVar2 = (uint *)(in_EAX + 8);
  do {
    uVar1 = puVar2[-2];
    if ((uVar1 < 0x30) || (0x39 < uVar1)) break;
    local_400[uVar4] = (byte)uVar1;
    uVar1 = puVar2[-1];
    if ((uVar1 < 0x30) || (0x39 < uVar1)) {
      uVar4 = uVar4 + 1;
      break;
    }
    local_400[uVar4 + 1] = (byte)uVar1;
    uVar1 = *puVar2;
    if ((uVar1 < 0x30) || (0x39 < uVar1)) {
      uVar4 = uVar4 + 2;
      break;
    }
    local_400[uVar4 + 2] = (byte)uVar1;
    uVar1 = puVar2[1];
    if ((uVar1 < 0x30) || (0x39 < uVar1)) {
      uVar4 = uVar4 + 3;
      break;
    }
    local_400[uVar4 + 3] = (byte)uVar1;
    uVar4 = uVar4 + 4;
    puVar2 = puVar2 + 4;
  } while (uVar4 < 0x400);
  iVar3 = 0;
  iVar5 = 1;
  uVar1 = uVar4;
  while (uVar1 = uVar1 - 1, -1 < (int)uVar1) {
    iVar3 = iVar3 + (local_400[uVar1] - 0x30) * iVar5;
    iVar5 = iVar5 * 10;
  }
  if (unaff_EDI != (uint *)0x0) {
    *unaff_EDI = uVar4;
  }
  return iVar3;
}

