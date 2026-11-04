
int FUN_007a44b0(short param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (int)param_1 * (int)param_1 + 0x1000 >> 0xd;
  iVar2 = (int)(short)iVar1;
  return (((short)((short)((short)((short)(iVar2 * -0x272 + 0x4000 >> 0xf) + 0x2055) * iVar2 +
                           0x4000 >> 0xf) + -0x1de3) * iVar2 + 0x4000 >> 0xf) - iVar1) + 0x8000;
}

