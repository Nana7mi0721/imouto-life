
uint * FUN_0050d3c2(uint *param_1,uint param_2)

{
  byte bVar1;
  byte bVar2;
  _ptiddata p_Var3;
  pthreadmbcinfo ptVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  
  p_Var3 = __getptd();
  ptVar4 = p_Var3->_tpxcptinfoptrs;
  if (ptVar4 != DAT_00f488fc) {
    ptVar4 = ___updatetmbcinfo();
  }
  if (ptVar4->ismbcodepage == 0) {
    while (((uint)param_1 & 3) != 0) {
      uVar8 = *param_1;
      if ((byte)uVar8 == (byte)param_2) {
        return param_1;
      }
      param_1 = (uint *)((int)param_1 + 1);
      if ((byte)uVar8 == 0) {
        return (uint *)0x0;
      }
    }
    while( true ) {
      while( true ) {
        uVar8 = *param_1;
        uVar7 = uVar8 ^ CONCAT22(CONCAT11((byte)param_2,(byte)param_2),
                                 CONCAT11((byte)param_2,(byte)param_2));
        uVar5 = uVar8 ^ 0xffffffff ^ uVar8 + 0x7efefeff;
        puVar6 = param_1 + 1;
        if (((uVar7 ^ 0xffffffff ^ uVar7 + 0x7efefeff) & 0x81010100) != 0) break;
        param_1 = puVar6;
        if ((uVar5 & 0x81010100) != 0) {
          if ((uVar5 & 0x1010100) != 0) {
            return (uint *)0x0;
          }
          if ((uVar8 + 0x7efefeff & 0x80000000) == 0) {
            return (uint *)0x0;
          }
        }
      }
      uVar8 = *param_1;
      if ((byte)uVar8 == (byte)param_2) {
        return param_1;
      }
      if ((byte)uVar8 == 0) {
        return (uint *)0x0;
      }
      bVar2 = (byte)(uVar8 >> 8);
      if (bVar2 == (byte)param_2) {
        return (uint *)((int)param_1 + 1);
      }
      if (bVar2 == 0) break;
      bVar2 = (byte)(uVar8 >> 0x10);
      if (bVar2 == (byte)param_2) {
        return (uint *)((int)param_1 + 2);
      }
      if (bVar2 == 0) {
        return (uint *)0x0;
      }
      bVar2 = (byte)(uVar8 >> 0x18);
      if (bVar2 == (byte)param_2) {
        return (uint *)((int)param_1 + 3);
      }
      param_1 = puVar6;
      if (bVar2 == 0) {
        return (uint *)0x0;
      }
    }
    return (uint *)0x0;
  }
  while( true ) {
    bVar2 = (byte)*param_1;
    uVar8 = (uint)bVar2;
    if (bVar2 == 0) break;
    if ((ptVar4->mbctype[uVar8 + 5] & 4) == 0) {
      puVar6 = param_1;
      if (param_2 == uVar8) break;
    }
    else {
      bVar1 = *(byte *)((int)param_1 + 1);
      if (bVar1 == 0) {
        return (uint *)0x0;
      }
      puVar6 = (uint *)((int)param_1 + 1);
      if (param_2 == CONCAT11(bVar2,bVar1)) {
        return param_1;
      }
    }
    param_1 = (uint *)((int)puVar6 + 1);
  }
  return (uint *)(~-(uint)(param_2 != uVar8) & (uint)param_1);
}

