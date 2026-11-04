
undefined4 FUN_00582a10(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint uVar5;
  undefined1 local_568 [172];
  undefined1 local_4bc [108];
  undefined4 local_450;
  undefined1 local_440 [1076];
  int local_c;
  
  iVar1 = FUN_00546d10(0x100,8,local_440);
  if (iVar1 < 0) {
    return 0xffffffff;
  }
  uVar5 = 0;
  puVar4 = (uint *)(local_c + 0x800);
  do {
    uVar2 = (uVar5 << 8 | uVar5) << 8 | uVar5;
    puVar4[-0x200] = uVar2;
    puVar4[-0x100] = uVar2;
    *puVar4 = uVar2;
    puVar4[0x100] = uVar2;
    puVar4[0x200] = uVar2;
    puVar4[0x300] = uVar2;
    puVar4[0x400] = uVar2;
    puVar4[0x500] = uVar2;
    uVar5 = uVar5 + 1;
    puVar4 = puVar4 + 1;
  } while (uVar5 < 0x100);
  FUN_00524a70(local_568);
  local_450 = 1;
  FUN_005194a0(local_4bc,0x20,1,0);
  uVar3 = FUN_00529e40(local_568,0,0xffffffff,local_440,0,1,0,0,0);
  FUN_005421c0(local_440);
  return uVar3;
}

