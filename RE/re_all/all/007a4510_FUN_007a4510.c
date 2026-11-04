
int FUN_007a4510(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = FUN_007a22e0(param_2);
  iVar2 = FUN_007a22e0(param_1);
  iVar3 = (int)(short)(param_2 << (0xfU - (char)iVar1 & 0x1f));
  iVar4 = (int)(short)(param_1 << (0xfU - (char)iVar2 & 0x1f));
  return (((short)((short)(iVar4 * -0xa25 + 0x4000 >> 0xf) + 0x1efc) * iVar4 + 0x4000 >> 0xf) -
         ((short)((short)(iVar3 * -0xa25 + 0x4000 >> 0xf) + 0x1efc) * iVar3 + 0x4000 >> 0xf)) +
         (iVar2 - iVar1) * 0x800;
}

