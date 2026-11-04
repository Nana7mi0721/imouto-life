
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00488290(int param_1)

{
  double dVar1;
  double dVar2;
  int iVar3;
  bool local_1c;
  
  iVar3 = FUN_004fe844();
  dVar2 = ((double)(iVar3 + *(int *)(param_1 + 0xf8)) -
          ((double)DAT_0084b244 * *(double *)(param_1 + 0x80)) / _DAT_00829888) + _DAT_00802e18;
  iVar3 = FUN_004e5650();
  dVar1 = (double)iVar3;
  local_1c = (!NAN(dVar1) && !NAN(dVar2)) && dVar1 < dVar2 != (dVar1 == dVar2);
  return CONCAT31((int3)(CONCAT22((short)((uint)iVar3 >> 0x10),
                                  (ushort)(dVar1 < dVar2) << 8 |
                                  (ushort)(NAN(dVar1) || NAN(dVar2)) << 10 |
                                  (ushort)(dVar1 == dVar2) << 0xe) >> 8),local_1c);
}

