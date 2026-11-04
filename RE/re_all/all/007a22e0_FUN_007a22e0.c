
int FUN_007a22e0(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = (uint)((param_1 & 0xffff0000) != 0) * 0x10;
  uVar1 = param_1 >> (sbyte)uVar2;
  uVar3 = (uint)((uVar1 & 0xff00) != 0) * 8;
  uVar1 = uVar1 >> (sbyte)uVar3;
  uVar4 = (uint)((uVar1 & 0xf0) != 0) << 2;
  uVar1 = uVar1 >> (sbyte)uVar4;
  uVar5 = (uint)((uVar1 & 0xc) != 0) << 1;
  return ((uVar1 >> (sbyte)uVar5) >> 1 & 1) + (uVar5 | param_1 != 0 | uVar2 | uVar3 | uVar4);
}

