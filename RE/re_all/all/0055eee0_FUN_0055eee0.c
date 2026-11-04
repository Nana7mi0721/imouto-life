
undefined4 FUN_0055eee0(void)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  int *piVar6;
  uint local_c;
  int local_8;
  int local_4;
  
  local_8 = FUN_00550060(0);
  local_4 = 0;
  puVar5 = &DAT_00a83e70;
  piVar6 = &DAT_00a83e84;
  uVar4 = local_c;
  do {
    puVar1 = puVar5 + -0x6e;
    if (puVar5[-0x6e] == 0) {
LAB_0055ef7a:
      uVar2 = *puVar5;
      local_c = uVar4 >> 1;
      uVar4 = local_c;
      if (local_c < uVar2) {
        if (0x1588 < uVar2 - local_c) {
          if (local_c < uVar2) goto LAB_0055efb2;
          goto LAB_0055ef97;
        }
      }
      else {
LAB_0055ef97:
        if (0x1588 < (uVar2 - local_c) + 0x5622) goto LAB_0055efb2;
      }
      FUN_0055c8c0();
      uVar4 = local_c;
    }
    else {
      if (DAT_00a83c64 == 0) {
        uVar2 = FUN_0057e790(puVar1);
      }
      else {
        uVar2 = puVar5[-0x5a];
        uVar4 = local_c;
      }
      if (uVar2 != 0) {
        if (*puVar1 != 0) {
          if (DAT_00a83c64 == 0) {
            iVar3 = FUN_0057ee10(puVar1,&local_c,0);
            if (iVar3 != 2) {
              uVar4 = local_c;
              goto LAB_0055ef7a;
            }
          }
          uVar4 = (uint)(ushort)puVar5[-0x5f] * puVar5[-0x59];
        }
        goto LAB_0055ef7a;
      }
    }
LAB_0055efb2:
    if ((*piVar6 != 0) && ((0xf < local_8 - piVar6[1] || (local_8 < piVar6[1])))) {
      if (piVar6[-0x73] != 0) {
        piVar6[-0x71] = 0;
        FUN_00551a70(piVar6 + -0x73);
      }
      *piVar6 = 0;
      piVar6[1] = 0;
    }
    if ((piVar6[2] != 0) && ((0xf < local_8 - piVar6[3] || (local_8 < piVar6[3])))) {
      if (piVar6[-0x73] != 0) {
        if (DAT_00a83c64 == 0) {
          FUN_0057e730(piVar6 + -0x73,0);
        }
        else {
          piVar6[-0x5f] = 0;
        }
      }
      piVar6[2] = 0;
      piVar6[3] = 0;
    }
    local_4 = local_4 + 1;
    piVar6 = piVar6 + 0x77;
    puVar5 = puVar5 + 0x77;
    if (0xa84417 < (int)piVar6) {
      return 0;
    }
  } while( true );
}

