
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004c1490(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  float10 fVar3;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_10;
  int local_c;
  int local_8;
  
  *(undefined4 *)(param_1 + 0xa470) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xa46c) = 0;
  uVar1 = FUN_00550060(0);
  *(undefined4 *)(param_1 + 0xa474) = uVar1;
  FUN_004c0d40();
  uVar1 = FUN_004fe844();
  *(undefined4 *)(param_1 + 0xa478) = uVar1;
  uVar1 = FUN_004fe844();
  *(undefined4 *)(param_1 + 0xa47c) = uVar1;
  uVar1 = FUN_004fe844();
  *(undefined4 *)(param_1 + 0xa480) = uVar1;
  uVar1 = FUN_004fe844();
  *(undefined4 *)(param_1 + 0xa48c) = uVar1;
  *(undefined4 *)(param_1 + 0xa488) = *(undefined4 *)(param_1 + 0xa48c);
  *(undefined4 *)(param_1 + 0xa484) = *(undefined4 *)(param_1 + 0xa488);
  local_c = 0;
  local_8 = 0;
  FUN_0052ece0();
  FUN_0042c860();
  while( true ) {
    iVar2 = FUN_0052ece0();
    if (iVar2 != 0) {
      return;
    }
    if (DAT_00a18a3c < 0x36) {
      iVar2 = FUN_00550060(0);
      if ((iVar2 - *(int *)(param_1 + 0xa474)) - *(int *)(param_1 + 0xa478) < 0) {
        local_18 = 0;
      }
      else {
        iVar2 = FUN_00550060(0);
        local_18 = (iVar2 - *(int *)(param_1 + 0xa474)) - *(int *)(param_1 + 0xa478);
      }
      local_c = local_c + local_18;
      if (*(char *)(param_1 + 0xa468) == '\0') {
        iVar2 = FUN_00550060(0);
        local_c = (iVar2 - *(int *)(param_1 + 0xa474)) - *(int *)(param_1 + 0xa478);
      }
      *(undefined4 *)(param_1 + 0xa48c) = *(undefined4 *)(param_1 + 0xa488);
      *(undefined4 *)(param_1 + 0xa488) = *(undefined4 *)(param_1 + 0xa484);
      iVar2 = FUN_00550060(0);
      *(int *)(param_1 + 0xa484) = iVar2 - *(int *)(param_1 + 0xa474);
      if (local_c < 1) {
        if (*(char *)(param_1 + 0xa468) != '\0') {
          if (*(int *)(param_1 + 0xa480) -
              (*(int *)(param_1 + 0xa484) + *(int *)(param_1 + 0xa488) + *(int *)(param_1 + 0xa48c))
              < 0) {
            local_1c = 0;
          }
          else {
            local_1c = *(int *)(param_1 + 0xa480) -
                       (*(int *)(param_1 + 0xa484) + *(int *)(param_1 + 0xa488) +
                       *(int *)(param_1 + 0xa48c));
          }
          FUN_0052eb30(local_1c);
          if (*(int *)(param_1 + 0xa480) -
              (*(int *)(param_1 + 0xa484) + *(int *)(param_1 + 0xa488) + *(int *)(param_1 + 0xa48c))
              < 0) {
            local_20 = 0;
          }
          else {
            local_20 = *(int *)(param_1 + 0xa480) -
                       (*(int *)(param_1 + 0xa484) + *(int *)(param_1 + 0xa488) +
                       *(int *)(param_1 + 0xa48c));
          }
          *(int *)(param_1 + 0xa484) = *(int *)(param_1 + 0xa484) + local_20;
        }
        local_8 = 0;
        *(undefined1 *)(param_1 + 0xa468) = 1;
      }
      else {
        *(undefined1 *)(param_1 + 0xa468) = 0;
        local_8 = local_8 + 1;
        if (1 < local_8) {
          *(undefined1 *)(param_1 + 0xa468) = 1;
          local_8 = 0;
          local_c = 0;
        }
      }
    }
    else {
      *(undefined4 *)(param_1 + 0xa48c) = *(undefined4 *)(param_1 + 0xa488);
      *(undefined4 *)(param_1 + 0xa488) = *(undefined4 *)(param_1 + 0xa484);
      iVar2 = FUN_00550060(0);
      *(int *)(param_1 + 0xa484) = iVar2 - *(int *)(param_1 + 0xa474);
      local_c = 0;
      iVar2 = FUN_00550060(0);
      if (0x10 - (iVar2 - *(int *)(param_1 + 0xa474)) < 0) {
        local_24 = 0;
      }
      else {
        iVar2 = FUN_00550060(0);
        local_24 = 0x10 - (iVar2 - *(int *)(param_1 + 0xa474));
      }
      FUN_0052eb30(local_24);
      if ((float)_DAT_00802e18 <= *(float *)(param_1 + 0xa46c)) {
        *(undefined1 *)(param_1 + 0xa468) = 1;
      }
    }
    fVar3 = (float10)FUN_004bd490();
    *(float *)(param_1 + 0xa46c) = (float)(fVar3 + (float10)*(float *)(param_1 + 0xa46c));
    uVar1 = FUN_00550060(0);
    *(undefined4 *)(param_1 + 0xa474) = uVar1;
    _DAT_00a140c8 = 0;
    FUN_0042c8b0();
    if ((DAT_00a117ac != '\0') && (DAT_00a117ad != '\0')) break;
    for (local_10 = 4; 0 < local_10; local_10 = local_10 + -1) {
      *(undefined4 *)(&DAT_00a140d0 + local_10 * 4) = *(undefined4 *)(&DAT_00a140cc + local_10 * 4);
    }
    _DAT_00a140d0 = FUN_00550060(0);
    FUN_004c1bb0();
    FUN_00433b10(0);
    FUN_0042f5b0(1);
    if (DAT_00a13fa0 != 1) {
      FUN_004c1a20();
      FUN_004c1ae0();
      uVar1 = 0;
      FUN_00401000(0);
      FUN_00401470(uVar1);
      FUN_0047ce50();
      FUN_0047dcf0(1);
      return;
    }
    if ((DAT_00a117ac == '\0') || (DAT_00a14664 == '\0')) {
      *(undefined4 *)(param_1 + 0xa478) = *(undefined4 *)(param_1 + 0xa47c);
    }
    else if (DAT_00a14666 == '\0') {
      *(undefined4 *)(param_1 + 0xa478) = 5;
    }
    else {
      *(undefined4 *)(param_1 + 0xa478) = 1;
    }
    if ((DAT_00a117ac != '\0') && (DAT_00a14665 != '\0')) {
      DAT_00a117ad = '\x01';
    }
  }
  DAT_00a117ac = 0;
  DAT_00a117ad = 0;
  DAT_00a13fa0 = 0;
  FUN_004c1a20();
  FUN_004c1ae0();
  return;
}

