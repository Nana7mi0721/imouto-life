
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_005a7f60(uint param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  
  DAT_00e39a00 = 0;
  DAT_00a3d360 = 0;
  if ((DAT_00a37dc8 == 0) || (DAT_00ddb360 != 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  iVar8 = 1;
  uVar6 = param_1 >> 0xb & 1;
  if ((param_1 & 0x2000) == 0) {
    FUN_0059b780(1);
    iVar3 = DAT_00e39a54;
    if ((((DAT_00e80620 == 0) && (iVar3 = DAT_00e80624, DAT_00e39a54 != 0)) || (iVar3 != 0)) &&
       (DAT_00f3a04c != 0)) {
      if ((DAT_00e39a54 != 0) || (DAT_00e80624 != 0)) {
        FUN_005d3d20(0);
        DAT_00e80624 = 0;
      }
      DAT_00e80620 = 0;
      DAT_00e39a00 = 1;
    }
  }
  if (((DAT_00e80618 != 0) || (DAT_00e39a54 != 0)) && (DAT_00f3a04c != 0)) {
    DAT_00e80618 = 0;
  }
  if ((((DAT_00e80630 != 0) || (DAT_00e80634 != 0)) || (DAT_00e39a54 != 0)) && (DAT_00f3a04c != 0))
  {
    DAT_00e80630 = 0;
    DAT_00e80634 = 0;
  }
  if (((param_1 & 0x200) == 0) || (DAT_00a38de0 != 0)) {
    if (DAT_00e804a0 == 1) {
      FUN_0059b2b0(0);
    }
  }
  else {
    if (DAT_00a3d258 == 0) {
      if (DAT_00e804a0 == 0) {
        FUN_0059b2b0(1);
      }
    }
    else {
      FUN_00524c30();
    }
    if (DAT_00a38de4 != 0) {
      DAT_00a38de4 = 0;
      FUN_005a7a00(&DAT_00a38de8);
    }
    if ((DAT_00a38e3c == 0) != DAT_00e804f8) {
      FUN_005a0440((uint)(DAT_00a38e3c == 0));
    }
    if ((DAT_00a38e40 == 0) != DAT_00e804fc) {
      FUN_005a0510((uint)(DAT_00a38e40 == 0));
    }
  }
  if ((DAT_00a380f4 != 0) || ((param_1 & 0x400) == 0)) {
    iVar8 = 0;
  }
  if (iVar8 != DAT_00e80b5c) {
    FUN_0059a900(iVar8);
  }
  if (uVar6 == 0) {
    if (DAT_00a37fb0 != 0) {
      if (DAT_00e80b78 != DAT_00a37fb0) {
        FUN_0059a710(DAT_00a37fb0);
      }
      if (DAT_00e80b80 != DAT_00a37fb4) {
        FUN_0059a780(DAT_00a37fb4);
      }
      if (DAT_00e80b7c != DAT_00a37fb8) {
        FUN_0059a7e0(DAT_00a37fb8);
      }
      iVar3 = DAT_00a37fbc;
      goto LAB_005a815c;
    }
    if (DAT_00e80b78 != 0) {
      FUN_0059a710(0);
    }
    if (DAT_00e80b80 != 0) {
      FUN_0059a780(0);
    }
  }
  else if (DAT_00a37fc0 == 0) {
    if (DAT_00e80b78 != 0) {
      FUN_0059a710(0);
    }
  }
  else {
    if (DAT_00e80b78 != DAT_00a37fc0) {
      FUN_0059a710(DAT_00a37fc0);
    }
    if (DAT_00e80b80 != DAT_00a37fc4) {
      FUN_0059a780(DAT_00a37fc4);
    }
    if (DAT_00e80b7c != DAT_00a37fc8) {
      FUN_0059a7e0(DAT_00a37fc8);
    }
    iVar3 = DAT_00a37fcc;
LAB_005a815c:
    if (DAT_00e79848 != iVar3) {
      FUN_0059a840(iVar3);
    }
  }
  if (DAT_00e79870 != DAT_00a37fd8) {
    FUN_0059a8a0(DAT_00a37fd8);
  }
  if ((param_1 & 0x80) == 0) {
    if (DAT_00e79874 != 0) {
      iVar3 = 0;
      goto LAB_005a8225;
    }
  }
  else if (DAT_00e79874 != DAT_00a380a0) {
    iVar3 = DAT_00a380a0;
LAB_005a8225:
    FUN_005a05e0(iVar3);
  }
  if ((param_1 & 0x100) == 0) {
    uVar5 = 0;
    uVar9 = 0;
    if ((param_1 & 0x8000) != 0) {
      if ((param_1 & 1) != 0) {
        uVar2 = param_1 >> 0x11 & 1;
        uVar4 = param_1 >> 0x10 & 1;
        if (uVar2 == 0) {
          if (uVar4 == 0) goto LAB_005a8294;
        }
        if (((DAT_00a380cc == 0) || (DAT_00a380cc == 8)) &&
           (((param_1 & 2) != 0 || (DAT_00a380bc != 1)))) {
          uVar5 = uVar2;
          uVar9 = uVar4;
        }
        else {
          uVar9 = 1;
        }
      }
    }
LAB_005a8294:
    if ((((param_1 & 0x20) == 0) && ((_DAT_00a38114 & 0xffffff) == 0xffffff)) && (DAT_00a38118 == 0)
       ) {
      iVar3 = 0;
    }
    else {
      iVar3 = 1;
    }
    if ((((param_1 & 0x40) == 0) && (DAT_00a380cc == 0)) && (DAT_00a37fd4 == 0)) {
      iVar7 = 0;
    }
    else {
      iVar7 = 1;
    }
    if (iVar3 != DAT_00e39a24) {
      FUN_0059bb70(iVar3);
    }
    if (iVar7 != DAT_00e39a28) {
      FUN_0059bb10(iVar7);
    }
    if (DAT_00e39a20 != DAT_00a3811c) {
      FUN_0059ba40(DAT_00a3811c);
    }
    if (((DAT_00e39a14 != DAT_00a380cc) || (DAT_00e39a08 != uVar5)) || (DAT_00e39a04 != uVar9)) {
      FUN_0059b9c0(DAT_00a380cc,uVar5,uVar9);
    }
    if ((DAT_00e39a0c != DAT_00a380ec) || (DAT_00e39a10 != DAT_00a380f0)) {
      FUN_0059baa0(DAT_00a380ec,DAT_00a380f0);
    }
    if ((DAT_00e39a18 == 0) && (DAT_00e39a1c == 0)) {
      if (!bVar1) goto LAB_005a83ff;
      if (DAT_00e80620 == 0) {
        if (uVar6 != 0) {
          if (iVar8 != 0) goto LAB_005a83ff;
          goto LAB_005a8395;
        }
        goto LAB_005a83c7;
      }
      if (((DAT_00e80620 != 1) || (uVar6 != 1)) || (iVar8 == 0)) goto LAB_005a83ff;
      uVar10 = 0;
    }
    else {
LAB_005a8395:
      if ((uVar6 == 0) || (iVar8 == 0)) {
LAB_005a83c7:
        uVar10 = 1;
      }
      else {
        uVar10 = 0;
      }
    }
  }
  else {
    if (!bVar1) goto LAB_005a83ff;
    if (DAT_00e80620 == 0) {
      if ((uVar6 != 0) && (iVar8 != 0)) goto LAB_005a83ff;
      uVar10 = 1;
    }
    else {
      if (((DAT_00e80620 != 1) || (uVar6 != 1)) || (iVar8 == 0)) goto LAB_005a83ff;
      uVar10 = 0;
    }
  }
  FUN_005a0d80(0,0,1,uVar10);
LAB_005a83ff:
  iVar8 = ((param_1 & 8) != 0) + 1;
  if (DAT_00e80638 != iVar8) {
    FUN_0059a9e0(iVar8);
  }
  if (DAT_00e7984c != DAT_00a380bc) {
    FUN_0059b3f0(DAT_00a380bc);
  }
  if (DAT_00e80500 != DAT_00a380c0) {
    FUN_0059b300(DAT_00a380c0,0xffffffff);
  }
  if ((param_1 & 0x4000) == 0) {
    if ((DAT_00e79844 != 0) && (DAT_00f3a04c != 0)) {
      if ((DAT_00e39a54 == 0) && (FUN_00568ca0(0), DAT_00dda46c != 0)) {
        FUN_00584d70();
      }
      FUN_005d3a70(0x16,1);
      DAT_00e79844 = 0;
      DAT_00e39a00 = 1;
    }
  }
  else if (DAT_00e79844 != DAT_00a37fdc) {
    FUN_0059a970(DAT_00a37fdc);
  }
  if (DAT_00a38d34 == 0) {
    FUN_0059b110(DAT_00a38d30,&DAT_00a38d38,0xffffffff);
    DAT_00a38d34 = 1;
    DAT_00e39a00 = 1;
  }
  if ((param_1 & 0x1000) == 0) {
    if ((DAT_00e8065c != 3) || (DAT_00e8069c != 3)) {
      FUN_0059aa40(3,0);
    }
    if ((DAT_00e80660 != 3) || (DAT_00e806a0 != 3)) {
      FUN_0059aa40(3,1);
    }
    if ((DAT_00e80664 != 3) || (DAT_00e806a4 != 3)) {
      FUN_0059aa40(3,2);
    }
    if ((DAT_00e80668 == 3) && (DAT_00e806a8 == 3)) {
      DAT_00e399fc = param_1;
      return;
    }
    FUN_0059aa40(3,3);
    DAT_00e399fc = param_1;
    return;
  }
  if (DAT_00e8065c != DAT_00a37fe0) {
    FUN_0059ac30(DAT_00a37fe0,0);
  }
  if (DAT_00e80660 != DAT_00a37fe4) {
    FUN_0059ac30(DAT_00a37fe4,1);
  }
  if (DAT_00e80664 != DAT_00a37fe8) {
    FUN_0059ac30(DAT_00a37fe8,2);
  }
  if (DAT_00e80668 != DAT_00a37fec) {
    FUN_0059ac30(DAT_00a37fec,3);
  }
  if (DAT_00e8066c != DAT_00a37ff0) {
    FUN_0059ac30(DAT_00a37ff0,4);
  }
  if (DAT_00e80670 != DAT_00a37ff4) {
    FUN_0059ac30(DAT_00a37ff4,5);
  }
  if (DAT_00e80674 != DAT_00a37ff8) {
    FUN_0059ac30(DAT_00a37ff8,6);
  }
  if (DAT_00e80678 != DAT_00a37ffc) {
    FUN_0059ac30(DAT_00a37ffc,7);
  }
  if (DAT_00e8069c != DAT_00a38020) {
    FUN_0059adc0(DAT_00a38020,0);
  }
  if (DAT_00e806a0 != DAT_00a38024) {
    FUN_0059adc0(DAT_00a38024,1);
  }
  if (DAT_00e806a4 != DAT_00a38028) {
    FUN_0059adc0(DAT_00a38028,2);
  }
  if (DAT_00e806a8 != DAT_00a3802c) {
    FUN_0059adc0(DAT_00a3802c,3);
  }
  if (DAT_00e806ac != DAT_00a38030) {
    FUN_0059adc0(DAT_00a38030,4);
  }
  if (DAT_00e806b0 != DAT_00a38034) {
    FUN_0059adc0(DAT_00a38034,5);
  }
  if (DAT_00e806b4 != DAT_00a38038) {
    FUN_0059adc0(DAT_00a38038,6);
  }
  if (DAT_00e806b8 != DAT_00a3803c) {
    FUN_0059adc0(DAT_00a3803c,7);
  }
  DAT_00e399fc = param_1;
  return;
}

