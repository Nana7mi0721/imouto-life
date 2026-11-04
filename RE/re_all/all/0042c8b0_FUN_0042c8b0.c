
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0042c8b0(char *param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  bool bVar5;
  float10 fVar6;
  char local_b8;
  char local_b4;
  char local_b0;
  char local_ac;
  char local_a8;
  char local_a4;
  char local_a0;
  char local_9c;
  char local_98;
  char local_94;
  char local_90;
  char local_8c;
  int local_88;
  int local_84;
  char local_64;
  char local_60;
  char local_5c;
  char local_58;
  char local_4c;
  char local_48;
  char local_44;
  char local_40;
  char local_3f;
  char local_3e;
  char local_3d;
  char local_3c;
  char local_3b;
  char local_3a;
  char local_39;
  char local_21;
  int local_14;
  
  if ((DAT_00a117ac == '\0') || (DAT_00a117ad == '\0')) {
    param_1[3] = '\0';
    param_1[4] = '\0';
    param_1[5] = '\0';
    param_1[6] = '\0';
    param_1[7] = '\0';
    param_1[8] = '\0';
    param_1[0x4e5] = '\0';
    iVar2 = FUN_0050e880();
    bVar5 = iVar2 != 0;
    param_1[0x2b8] = '\0';
    param_1[0x2b9] = '\0';
    param_1[0x2ba] = '\0';
    param_1[699] = '\0';
    if ((bVar5) && (param_1[0x4e4] != '\0')) {
      uVar3 = FUN_0054f980(1);
      *(undefined4 *)(param_1 + 0x2b8) = uVar3;
      FUN_0054fc10(1,param_1 + 0x4ec);
      iVar2 = FUN_0054fcb0(1,param_1 + 0x53c);
      if (iVar2 == 0) {
        if (9 < (byte)param_1[0x54c]) {
          *(uint *)(param_1 + 0x2b8) = *(uint *)(param_1 + 0x2b8) | 0x4000;
        }
        if (9 < (byte)param_1[0x54d]) {
          *(uint *)(param_1 + 0x2b8) = *(uint *)(param_1 + 0x2b8) | 0x8000;
        }
      }
      FUN_0054fc10(1,param_1 + 0x4ec);
    }
    _memset(param_1 + 0xa0,0,0x100);
    FUN_0054f910(param_1 + 0x1a0);
    if (bVar5) {
      FUN_0054f910(param_1 + 0xa0);
    }
    else {
      _memset(param_1 + 0xa0,0,0x100);
    }
    for (local_14 = 0; local_14 < 0x100; local_14 = local_14 + 1) {
      if (((param_1[local_14 + 0xa0] == '\0') || (param_1[local_14 + 0x3d5] == '\0')) &&
         (param_1[local_14 + 0x2c3] == '\0')) {
        local_21 = '\0';
      }
      else {
        local_21 = '\x01';
      }
      param_1[local_14 + 0xa0] = local_21;
    }
    param_1[0x2c] = '\0';
    param_1[0x2d] = '\0';
    param_1[0x2e] = '\0';
    param_1[0x2f] = '\0';
    param_1[0x28] = '\0';
    param_1[0x29] = '\0';
    param_1[0x2a] = '\0';
    param_1[0x2b] = '\0';
    if (DAT_00a117ac == '\0') {
      if ((param_1[0x2bf] != '\0') ||
         (((bVar5 && (param_1[0x4d8] != '\0')) &&
          (((*(uint *)(param_1 + 0x2b8) & 8) != 0 ||
           ((param_1[0x168] != '\0' || (param_1[0xe8] != '\0')))))))) {
        param_1[3] = '\x01';
      }
      if ((param_1[0x2c0] != '\0') ||
         (((bVar5 && (param_1[0x4d9] != '\0')) &&
          (((*(uint *)(param_1 + 0x2b8) & 1) != 0 ||
           ((param_1[0x170] != '\0' || (param_1[0xf0] != '\0')))))))) {
        param_1[4] = '\x01';
      }
      if ((param_1[0x2c1] != '\0') ||
         (((bVar5 && (param_1[0x4da] != '\0')) &&
          (((*(uint *)(param_1 + 0x2b8) & 2) != 0 ||
           ((param_1[0x16b] != '\0' || (param_1[0xeb] != '\0')))))))) {
        param_1[5] = '\x01';
      }
      if ((param_1[0x2c2] != '\0') ||
         (((bVar5 && (param_1[0x4db] != '\0')) &&
          (((*(uint *)(param_1 + 0x2b8) & 4) != 0 ||
           ((param_1[0x16d] != '\0' || (param_1[0xed] != '\0')))))))) {
        param_1[6] = '\x01';
      }
      param_1[0x1a] = '\0';
      param_1[0x1b] = '\0';
      param_1[0x1c] = '\0';
      param_1[0x1d] = '\0';
      param_1[0x1e] = '\0';
      param_1[0x1f] = '\0';
      if ((bVar5) && (param_1[0x4e3] != '\0')) {
        FUN_0054f460(param_1 + 0x20,param_1 + 0x24);
        fVar6 = (float10)FUN_0050e8d0(0,0);
        if (((float10)_DAT_00802e18 != fVar6) &&
           (fVar6 = (float10)FUN_0050e8d0(0,0), (float10)_DAT_00804a60 != fVar6)) {
          *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
          *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
        }
      }
      if (*(int *)(param_1 + 0x3c8) != -1000) {
        *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x3c8);
      }
      if (*(int *)(param_1 + 0x3cc) != -1000) {
        *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x3cc);
      }
      if ((((*(int *)(param_1 + 0x20) < 0) || (DAT_0084b230 < *(int *)(param_1 + 0x20))) ||
          (*(int *)(param_1 + 0x24) < 0)) || (DAT_0084b234 < *(int *)(param_1 + 0x24))) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if ((((param_1[0x3c3] != '\0') ||
           (((bVar1 && (bVar5)) &&
            ((param_1[0x4e3] != '\0' && (uVar4 = FUN_0054f4c0(), (uVar4 & 1) != 0)))))) ||
          ((((!bVar1 && (bVar5)) && (param_1[0x4e3] != '\0')) &&
           ((*param_1 != '\0' && (uVar4 = FUN_0054f4c0(), (uVar4 & 1) != 0)))))) &&
         (param_1[0x1a] = '\x01', *param_1 == '\0')) {
        param_1[0x1d] = '\x01';
      }
      if ((((param_1[0x3c5] != '\0') ||
           ((((bVar1 && (bVar5)) && (param_1[0x4e3] != '\0')) &&
            (uVar4 = FUN_0054f4c0(), (uVar4 & 2) != 0)))) ||
          (((!bVar1 && (bVar5)) &&
           ((param_1[0x4e3] != '\0' &&
            ((param_1[1] != '\0' && (uVar4 = FUN_0054f4c0(), (uVar4 & 2) != 0)))))))) &&
         (param_1[0x1b] = '\x01', param_1[1] == '\0')) {
        param_1[0x1e] = '\x01';
      }
      if ((((param_1[0x3c4] != '\0') ||
           ((((bVar1 && (bVar5)) && (param_1[0x4e3] != '\0')) &&
            (uVar4 = FUN_0054f4c0(), (uVar4 & 4) != 0)))) ||
          (((!bVar1 && (bVar5)) &&
           ((param_1[0x4e3] != '\0' &&
            ((param_1[2] != '\0' && (uVar4 = FUN_0054f4c0(), (uVar4 & 4) != 0)))))))) &&
         (param_1[0x1c] = '\x01', param_1[2] == '\0')) {
        param_1[0x1f] = '\x01';
      }
      *param_1 = param_1[0x1a];
      param_1[1] = param_1[0x1b];
      param_1[2] = param_1[0x1c];
      if (param_1[0x3c6] == '\0') {
        if ((bVar5) && (param_1[0x4e3] != '\0')) {
          uVar3 = FUN_0050f5e0(1);
          *(undefined4 *)(param_1 + 0x40) = uVar3;
          if ((DAT_00a1b134 == '\0') || (DAT_00a1b133 == '\0')) {
            param_1[0x40] = '\0';
            param_1[0x41] = '\0';
            param_1[0x42] = '\0';
            param_1[0x43] = '\0';
          }
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_1 + 0x3d0);
      }
      *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_1 + 0x20);
      *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_1 + 0x24);
      if (DAT_00a18c70 == '\0') {
        FUN_0050e880();
        iVar2 = FUN_0050e880();
        if ((iVar2 == 0) ||
           ((*(int *)(param_1 + 0x24) < -1 && (iVar2 = FUN_0050e890(), iVar2 == 0)))) {
          FUN_0050f160(1);
        }
        else if ((-1 < *(int *)(param_1 + 0x24)) && (iVar2 = FUN_0050e890(), iVar2 != 0)) {
          FUN_0050f160(0);
        }
      }
      if (DAT_0084b230 < *(int *)(param_1 + 0x20)) {
        *(int *)(param_1 + 0x20) = DAT_0084b230;
      }
      if (*(int *)(param_1 + 0x20) < 0) {
        param_1[0x20] = '\0';
        param_1[0x21] = '\0';
        param_1[0x22] = '\0';
        param_1[0x23] = '\0';
      }
      if (DAT_0084b234 < *(int *)(param_1 + 0x24)) {
        *(int *)(param_1 + 0x24) = DAT_0084b234;
      }
      if (*(int *)(param_1 + 0x24) < 0) {
        param_1[0x24] = '\0';
        param_1[0x25] = '\0';
        param_1[0x26] = '\0';
        param_1[0x27] = '\0';
      }
      if (DAT_0084b248 == 2) {
        *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) / 2;
        *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) / 2;
      }
      *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x20) - *(int *)(param_1 + 0x90);
      *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x94);
      *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0x20);
      *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0x24);
      if (bVar5) {
        if ((param_1[0x13d] == '\0') && (param_1[0xbd] == '\0')) {
          local_39 = '\0';
        }
        else {
          local_39 = '\x01';
        }
        local_3a = local_39;
      }
      else {
        local_3a = '\0';
      }
      param_1[7] = local_3a;
      if (bVar5) {
        if ((param_1[0xca] == '\0') && (param_1[0xd6] == '\0')) {
          local_3b = '\0';
        }
        else {
          local_3b = '\x01';
        }
        local_3c = local_3b;
      }
      else {
        local_3c = '\0';
      }
      param_1[8] = local_3c;
      if (bVar5) {
        if (((param_1[0x157] == '\0') && (param_1[0xe6] == '\0')) && (param_1[0x165] == '\0')) {
          local_3d = '\0';
        }
        else {
          local_3d = '\x01';
        }
        local_3e = local_3d;
      }
      else {
        local_3e = '\0';
      }
      param_1[0x8b] = local_3e;
      param_1[9] = '\0';
      param_1[10] = '\0';
      param_1[0x8c] = '\0';
      if ((DAT_00a1b132 == '\0') && (param_1[8] != '\0')) {
        param_1[10] = '\x01';
      }
      if ((DAT_00a1b131 == '\0') && (param_1[7] != '\0')) {
        param_1[9] = '\x01';
      }
      if ((DAT_00a1b130 == '\0') && (param_1[0x8b] != '\0')) {
        param_1[0x8c] = '\x01';
      }
      DAT_00a1b132 = param_1[8];
      DAT_00a1b131 = param_1[7];
      DAT_00a1b130 = param_1[0x8b];
      if (bVar5) {
        if ((param_1[0xd8] == '\0') && (param_1[0x158] == '\0')) {
          local_3f = '\0';
        }
        else {
          local_3f = '\x01';
        }
        local_40 = local_3f;
      }
      else {
        local_40 = '\0';
      }
      param_1[0xb] = local_40;
      DAT_00a1b12f = param_1[0xb];
      param_1[0x2b4] = param_1[0xbc] != '\0';
      if ((DAT_00a1b12e == '\0') && (param_1[0x2b4] != '\0')) {
        local_44 = '\x01';
      }
      else {
        local_44 = '\0';
      }
      param_1[0x2b5] = local_44;
      DAT_00a1b12e = param_1[0x2b4];
      if ((param_1[0x27b] == '\0') && (param_1[0x27c] == '\0')) {
        local_48 = '\0';
      }
      else {
        local_48 = '\x01';
      }
      param_1[0x4e8] = local_48;
      if ((DAT_00a1b12d == '\0') && (param_1[0x4e8] != '\0')) {
        local_4c = '\x01';
      }
      else {
        local_4c = '\0';
      }
      param_1[0x4e9] = local_4c;
      DAT_00a1b12d = param_1[0x4e8];
      param_1[100] = '\0';
      param_1[0x65] = '\0';
      param_1[0x66] = '\0';
      param_1[0x67] = '\0';
      param_1[0x68] = '\0';
      param_1[0x69] = '\0';
      param_1[0x6a] = '\0';
      param_1[0x6b] = '\0';
      param_1[0x4e5] = '\0';
      param_1[0x4e6] = '\0';
      if ((param_1[700] != '\0') ||
         ((param_1[0x4d5] != '\0' &&
          (((((*(uint *)(param_1 + 0x2b8) & DAT_00a18b40) != 0 ||
             (param_1[DAT_00a18b34 + 0x3c] != '\0')) || (param_1[0xbc] != '\0')) ||
           ((param_1[0xd9] != '\0' || (param_1[0x13c] != '\0')))))))) {
        param_1[100] = '\x01';
        if (DAT_00a1b12c == '\0') {
          param_1[0x68] = '\x01';
        }
        else {
          param_1[0x68] = '\0';
        }
      }
      if ((param_1[0x2bd] != '\0') ||
         ((param_1[0x4d6] != '\0' &&
          ((((*(uint *)(param_1 + 0x2b8) & DAT_00a18b44) != 0 ||
            (param_1[DAT_00a18b38 + 0x3c] != '\0')) ||
           ((param_1[0xf2] != '\0' ||
            (((param_1[0x172] != '\0' || (param_1[0xa1] != '\0')) || (param_1[0xae] != '\0')))))))))
         ) {
        param_1[0x65] = '\x01';
        if (DAT_00a1b12b == '\0') {
          param_1[0x69] = '\x01';
        }
        else {
          param_1[0x69] = '\0';
        }
      }
      if ((param_1[0x2be] != '\0') ||
         ((param_1[0x4d7] != '\0' &&
          ((((*(uint *)(param_1 + 0x2b8) & DAT_00a18b48) != 0 || (param_1[0xca] != '\0')) ||
           ((param_1[0xd6] != '\0' || (param_1[DAT_00a18b3c + 0x3c] != '\0')))))))) {
        param_1[0x66] = '\x01';
        if (DAT_00a1b12a == '\0') {
          param_1[0x6a] = '\x01';
        }
        else {
          param_1[0x6a] = '\0';
        }
      }
      if ((bVar5) && ((*(uint *)(param_1 + 0x2b8) & 0x4000) != 0)) {
        param_1[0x67] = '\x01';
        if (DAT_00a1b129 == '\0') {
          param_1[0x6b] = '\x01';
        }
        else {
          param_1[0x6b] = '\0';
        }
      }
      if (param_1[0xa1] != '\0') {
        param_1[0x4e5] = '\x01';
        if (DAT_00a1b128 == '\0') {
          param_1[0x4e6] = '\x01';
        }
        else {
          param_1[0x4e6] = '\0';
        }
      }
      DAT_00a1b12c = param_1[100];
      DAT_00a1b12b = param_1[0x65];
      DAT_00a1b12a = param_1[0x66];
      DAT_00a1b129 = param_1[0x67];
      DAT_00a1b128 = param_1[0x4e5];
      param_1[0x6c] = param_1[100];
      param_1[0x6d] = param_1[0x65];
      param_1[0x6e] = param_1[0x66];
      param_1[0x6f] = param_1[0x67];
      DAT_00a1b133 = DAT_00a1b134;
      DAT_00a1b134 = bVar5;
      FUN_004711f0(param_1[3],param_1[4],param_1[5],param_1[6],param_1[0x6c],param_1[0x6d],
                   param_1[0x6e],param_1[0x6f]);
    }
    else {
      param_1[100] = '\0';
      param_1[0x65] = '\0';
      param_1[0x66] = '\0';
      param_1[0x67] = '\0';
      param_1[0x68] = '\0';
      param_1[0x69] = '\0';
      param_1[0x6a] = '\0';
      param_1[0x6b] = '\0';
      if ((((*(uint *)(param_1 + 0x2b8) & DAT_00a18b40) != 0) ||
          (param_1[DAT_00a18b34 + 0xa0] != '\0')) ||
         ((param_1[0xbc] != '\0' || (param_1[0xd9] != '\0')))) {
        param_1[100] = '\x01';
        if (DAT_00a1b12c == '\0') {
          param_1[0x68] = '\x01';
        }
        else {
          param_1[0x68] = '\0';
        }
      }
      if ((((*(uint *)(param_1 + 0x2b8) & DAT_00a18b44) != 0) ||
          (param_1[DAT_00a18b38 + 0xa0] != '\0')) ||
         ((param_1[0xf2] != '\0' ||
          ((((param_1[0x172] != '\0' || (param_1[0x134] != '\0')) || (param_1[0xa1] != '\0')) ||
           (param_1[0xae] != '\0')))))) {
        param_1[0x65] = '\x01';
        if (DAT_00a1b12b == '\0') {
          param_1[0x69] = '\x01';
        }
        else {
          param_1[0x69] = '\0';
        }
      }
      if ((((*(uint *)(param_1 + 0x2b8) & DAT_00a18b48) != 0) || (param_1[0xca] != '\0')) ||
         ((param_1[0xd6] != '\0' || (param_1[DAT_00a18b3c + 0xa0] != '\0')))) {
        param_1[0x66] = '\x01';
        if (DAT_00a1b12a == '\0') {
          param_1[0x6a] = '\x01';
        }
        else {
          param_1[0x6a] = '\0';
        }
      }
      FUN_004712f0(param_1 + 3,param_1 + 4,param_1 + 5,param_1 + 6,param_1 + 0x6c,param_1 + 0x6d,
                   param_1 + 0x6e,param_1 + 0x6f);
    }
    if ((DAT_00a1b127 == '\0') && (param_1[0x6c] != '\0')) {
      local_58 = '\x01';
    }
    else {
      local_58 = '\0';
    }
    param_1[0x70] = local_58;
    DAT_00a1b127 = param_1[0x6c];
    if ((DAT_00a1b126 == '\0') && (param_1[0x6d] != '\0')) {
      local_5c = '\x01';
    }
    else {
      local_5c = '\0';
    }
    param_1[0x71] = local_5c;
    DAT_00a1b126 = param_1[0x6d];
    if ((DAT_00a1b125 == '\0') && (param_1[0x6e] != '\0')) {
      local_60 = '\x01';
    }
    else {
      local_60 = '\0';
    }
    param_1[0x72] = local_60;
    DAT_00a1b125 = param_1[0x6e];
    if ((DAT_00a1b124 == '\0') && (param_1[0x6f] != '\0')) {
      local_64 = '\x01';
    }
    else {
      local_64 = '\0';
    }
    param_1[0x73] = local_64;
    DAT_00a1b124 = param_1[0x6f];
    if (param_1[0x6c] == '\0') {
      param_1[0x2a8] = '\0';
      param_1[0x2a9] = '\0';
      param_1[0x2aa] = '\0';
      param_1[0x2ab] = '\0';
    }
    else {
      *(int *)(param_1 + 0x2a8) = *(int *)(param_1 + 0x2a8) + 1;
    }
    if (param_1[0x6d] == '\0') {
      param_1[0x2ac] = '\0';
      param_1[0x2ad] = '\0';
      param_1[0x2ae] = '\0';
      param_1[0x2af] = '\0';
    }
    else {
      *(int *)(param_1 + 0x2ac) = *(int *)(param_1 + 0x2ac) + 1;
    }
    DAT_00a1b120 = DAT_00a1b120 + 1;
    if ((DAT_00a1b11f == '\0') && (param_1[3] != '\0')) {
      param_1[0x12] = '\x01';
      param_1[0x13] = '\0';
    }
    else if ((param_1[3] == '\0') && (param_1[0x12] = '\0', param_1[4] != '\0')) {
      param_1[0x13] = '\x01';
    }
    if ((DAT_00a1b11e == '\0') && (param_1[4] != '\0')) {
      param_1[0x12] = '\0';
      param_1[0x13] = '\x01';
    }
    else if ((param_1[4] == '\0') && (param_1[0x13] = '\0', param_1[3] != '\0')) {
      param_1[0x12] = '\x01';
    }
    if ((DAT_00a1b11d == '\0') && (param_1[5] != '\0')) {
      param_1[0x14] = '\x01';
      param_1[0x15] = '\0';
    }
    else if ((param_1[5] == '\0') && (param_1[0x14] = '\0', param_1[6] != '\0')) {
      param_1[0x15] = '\x01';
    }
    if ((DAT_00a1b11c == '\0') && (param_1[6] != '\0')) {
      param_1[0x15] = '\x01';
      param_1[0x14] = '\0';
    }
    else if ((param_1[6] == '\0') && (param_1[0x15] = '\0', param_1[5] != '\0')) {
      param_1[0x14] = '\x01';
    }
    param_1[0x4c] = '\0';
    param_1[0x4d] = '\0';
    param_1[0x4e] = '\0';
    param_1[0x4f] = '\0';
    param_1[0x58] = '\0';
    param_1[0x59] = '\0';
    param_1[0x5a] = '\0';
    param_1[0x5b] = '\0';
    if (param_1[0x12] == '\0') {
      if (param_1[0x13] == '\0') {
        if (param_1[0x14] == '\0') {
          if (param_1[0x15] == '\0') {
            DAT_00a1b120 = 0;
          }
          else {
            param_1[0x28] = '\x06';
            param_1[0x29] = '\0';
            param_1[0x2a] = '\0';
            param_1[0x2b] = '\0';
            param_1[0x58] = '\x06';
            param_1[0x59] = '\0';
            param_1[0x5a] = '\0';
            param_1[0x5b] = '\0';
          }
        }
        else {
          param_1[0x28] = '\x04';
          param_1[0x29] = '\0';
          param_1[0x2a] = '\0';
          param_1[0x2b] = '\0';
          param_1[0x58] = '\x04';
          param_1[0x59] = '\0';
          param_1[0x5a] = '\0';
          param_1[0x5b] = '\0';
        }
      }
      else {
        param_1[0x28] = '\x02';
        param_1[0x29] = '\0';
        param_1[0x2a] = '\0';
        param_1[0x2b] = '\0';
        if (param_1[0x14] == '\0') {
          if (param_1[0x15] != '\0') {
            param_1[0x28] = '\x03';
            param_1[0x29] = '\0';
            param_1[0x2a] = '\0';
            param_1[0x2b] = '\0';
          }
        }
        else {
          param_1[0x28] = '\x01';
          param_1[0x29] = '\0';
          param_1[0x2a] = '\0';
          param_1[0x2b] = '\0';
        }
      }
    }
    else {
      param_1[0x28] = '\b';
      param_1[0x29] = '\0';
      param_1[0x2a] = '\0';
      param_1[0x2b] = '\0';
      if (param_1[0x14] == '\0') {
        if (param_1[0x15] != '\0') {
          param_1[0x28] = '\t';
          param_1[0x29] = '\0';
          param_1[0x2a] = '\0';
          param_1[0x2b] = '\0';
        }
      }
      else {
        param_1[0x28] = '\a';
        param_1[0x29] = '\0';
        param_1[0x2a] = '\0';
        param_1[0x2b] = '\0';
      }
    }
    if (DAT_00a1b118 != *(int *)(param_1 + 0x28)) {
      DAT_00a1b120 = 0;
    }
    if ((DAT_00a1b11f == '\0') && (param_1[3] != '\0')) {
      param_1[0x19] = '\0';
      param_1[0x18] = '\0';
      param_1[0x17] = '\0';
      param_1[0x16] = '\0';
      param_1[0x16] = '\x01';
    }
    else if ((param_1[3] == '\0') &&
            ((((param_1[0x16] = '\0', param_1[0x16] == '\0' && (param_1[0x17] == '\0')) &&
              (param_1[0x18] == '\0')) && (param_1[0x19] == '\0')))) {
      if (param_1[4] == '\0') {
        if (param_1[5] == '\0') {
          if (param_1[6] != '\0') {
            param_1[0x19] = '\x01';
          }
        }
        else {
          param_1[0x18] = '\x01';
        }
      }
      else {
        param_1[0x17] = '\x01';
      }
    }
    if ((DAT_00a1b11e == '\0') && (param_1[4] != '\0')) {
      param_1[0x19] = '\0';
      param_1[0x18] = '\0';
      param_1[0x17] = '\0';
      param_1[0x16] = '\0';
      param_1[0x17] = '\x01';
    }
    else if ((((param_1[4] == '\0') &&
              ((param_1[0x17] = '\0', param_1[0x16] == '\0' && (param_1[0x17] == '\0')))) &&
             (param_1[0x18] == '\0')) && (param_1[0x19] == '\0')) {
      if (param_1[3] == '\0') {
        if (param_1[5] == '\0') {
          if (param_1[6] != '\0') {
            param_1[0x19] = '\x01';
          }
        }
        else {
          param_1[0x18] = '\x01';
        }
      }
      else {
        param_1[0x16] = '\x01';
      }
    }
    if ((DAT_00a1b11d == '\0') && (param_1[5] != '\0')) {
      param_1[0x19] = '\0';
      param_1[0x18] = '\0';
      param_1[0x17] = '\0';
      param_1[0x16] = '\0';
      param_1[0x18] = '\x01';
    }
    else if (((param_1[5] == '\0') &&
             (((param_1[0x18] = '\0', param_1[0x16] == '\0' && (param_1[0x17] == '\0')) &&
              (param_1[0x18] == '\0')))) && (param_1[0x19] == '\0')) {
      if (param_1[6] == '\0') {
        if (param_1[3] == '\0') {
          if (param_1[4] != '\0') {
            param_1[0x17] = '\x01';
          }
        }
        else {
          param_1[0x16] = '\x01';
        }
      }
      else {
        param_1[0x19] = '\x01';
      }
    }
    if ((DAT_00a1b11c == '\0') && (param_1[6] != '\0')) {
      param_1[0x19] = '\0';
      param_1[0x18] = '\0';
      param_1[0x17] = '\0';
      param_1[0x16] = '\0';
      param_1[0x19] = '\x01';
    }
    else if (((param_1[6] == '\0') &&
             ((param_1[0x19] = '\0', param_1[0x16] == '\0' && (param_1[0x17] == '\0')))) &&
            ((param_1[0x18] == '\0' && (param_1[0x19] == '\0')))) {
      if (param_1[5] == '\0') {
        if (param_1[3] == '\0') {
          if (param_1[4] != '\0') {
            param_1[0x17] = '\x01';
          }
        }
        else {
          param_1[0x16] = '\x01';
        }
      }
      else {
        param_1[0x18] = '\x01';
      }
    }
    if (param_1[0x16] != '\0') {
      param_1[0x2c] = '\b';
      param_1[0x2d] = '\0';
      param_1[0x2e] = '\0';
      param_1[0x2f] = '\0';
    }
    if (param_1[0x17] != '\0') {
      param_1[0x2c] = '\x02';
      param_1[0x2d] = '\0';
      param_1[0x2e] = '\0';
      param_1[0x2f] = '\0';
    }
    if (param_1[0x18] != '\0') {
      param_1[0x2c] = '\x04';
      param_1[0x2d] = '\0';
      param_1[0x2e] = '\0';
      param_1[0x2f] = '\0';
    }
    if (param_1[0x19] != '\0') {
      param_1[0x2c] = '\x06';
      param_1[0x2d] = '\0';
      param_1[0x2e] = '\0';
      param_1[0x2f] = '\0';
    }
    if (param_1[0x12] == '\0') {
      if (param_1[0x13] != '\0') {
        param_1[0x4c] = '\x02';
        param_1[0x4d] = '\0';
        param_1[0x4e] = '\0';
        param_1[0x4f] = '\0';
      }
    }
    else {
      param_1[0x4c] = '\b';
      param_1[0x4d] = '\0';
      param_1[0x4e] = '\0';
      param_1[0x4f] = '\0';
    }
    if (param_1[0x14] == '\0') {
      if (param_1[0x15] != '\0') {
        param_1[0x58] = '\x06';
        param_1[0x59] = '\0';
        param_1[0x5a] = '\0';
        param_1[0x5b] = '\0';
      }
    }
    else {
      param_1[0x58] = '\x04';
      param_1[0x59] = '\0';
      param_1[0x5a] = '\0';
      param_1[0x5b] = '\0';
    }
    param_1[0x30] = '\0';
    param_1[0x31] = '\0';
    param_1[0x32] = '\0';
    param_1[0x33] = '\0';
    if ((DAT_00a1b11f == '\0') && (param_1[3] != '\0')) {
      param_1[0xe] = '\x01';
      param_1[0x30] = '\b';
      param_1[0x31] = '\0';
      param_1[0x32] = '\0';
      param_1[0x33] = '\0';
    }
    else {
      param_1[0xe] = '\0';
    }
    if ((DAT_00a1b11e == '\0') && (param_1[4] != '\0')) {
      param_1[0xf] = '\x01';
      param_1[0x30] = '\x02';
      param_1[0x31] = '\0';
      param_1[0x32] = '\0';
      param_1[0x33] = '\0';
    }
    else {
      param_1[0xf] = '\0';
    }
    if ((DAT_00a1b11d == '\0') && (param_1[5] != '\0')) {
      param_1[0x10] = '\x01';
      param_1[0x30] = '\x04';
      param_1[0x31] = '\0';
      param_1[0x32] = '\0';
      param_1[0x33] = '\0';
    }
    else {
      param_1[0x10] = '\0';
    }
    if ((DAT_00a1b11c == '\0') && (param_1[6] != '\0')) {
      param_1[0x11] = '\x01';
      param_1[0x30] = '\x06';
      param_1[0x31] = '\0';
      param_1[0x32] = '\0';
      param_1[0x33] = '\0';
    }
    else {
      param_1[0x11] = '\0';
    }
    if (DAT_00a1b118 == *(int *)(param_1 + 0x28)) {
      param_1[0x38] = '\0';
      param_1[0x39] = '\0';
      param_1[0x3a] = '\0';
      param_1[0x3b] = '\0';
    }
    else {
      *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0x28);
    }
    *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0x30);
    *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 0x38);
    param_1[0x50] = '\0';
    param_1[0x51] = '\0';
    param_1[0x52] = '\0';
    param_1[0x53] = '\0';
    param_1[0x5c] = '\0';
    param_1[0x5d] = '\0';
    param_1[0x5e] = '\0';
    param_1[0x5f] = '\0';
    if (*(int *)(param_1 + 0x4c) == 2) {
      if (param_1[0xf] != '\0') {
        param_1[0x50] = '\x02';
        param_1[0x51] = '\0';
        param_1[0x52] = '\0';
        param_1[0x53] = '\0';
      }
    }
    else if ((*(int *)(param_1 + 0x4c) == 8) && (param_1[0xe] != '\0')) {
      param_1[0x50] = '\b';
      param_1[0x51] = '\0';
      param_1[0x52] = '\0';
      param_1[0x53] = '\0';
    }
    if (*(int *)(param_1 + 0x58) == 4) {
      if (param_1[0x10] != '\0') {
        param_1[0x5c] = '\x04';
        param_1[0x5d] = '\0';
        param_1[0x5e] = '\0';
        param_1[0x5f] = '\0';
      }
    }
    else if ((*(int *)(param_1 + 0x58) == 6) && (param_1[0x11] != '\0')) {
      param_1[0x5c] = '\x06';
      param_1[0x5d] = '\0';
      param_1[0x5e] = '\0';
      param_1[0x5f] = '\0';
    }
    *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x50);
    *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_1 + 0x5c);
    if (DAT_00a18ab8 / DAT_0084b244 < 1) {
      local_84 = 1;
    }
    else {
      local_84 = DAT_00a18ab8 / DAT_0084b244;
    }
    if (DAT_00a18abc / DAT_0084b244 < 1) {
      local_88 = 1;
    }
    else {
      local_88 = DAT_00a18abc / DAT_0084b244;
    }
    param_1[0x2a4] = '\0';
    param_1[0x2a5] = '\0';
    param_1[0x2a6] = '\0';
    param_1[0x2a7] = '\0';
    param_1[0x2a0] = '\0';
    param_1[0x2a1] = '\0';
    param_1[0x2a2] = '\0';
    param_1[0x2a3] = '\0';
    if ((*(int *)(param_1 + 0x2a8) == local_84) ||
       ((local_84 < *(int *)(param_1 + 0x2a8) &&
        ((*(int *)(param_1 + 0x2a8) - local_84) % local_88 == 0)))) {
      param_1[0x2a0] = '\x01';
      param_1[0x2a1] = '\0';
      param_1[0x2a2] = '\0';
      param_1[0x2a3] = '\0';
    }
    if ((*(int *)(param_1 + 0x2ac) == local_84) ||
       ((local_84 < *(int *)(param_1 + 0x2ac) &&
        ((*(int *)(param_1 + 0x2ac) - local_84) % local_88 == 0)))) {
      param_1[0x2a4] = '\x01';
      param_1[0x2a5] = '\0';
      param_1[0x2a6] = '\0';
      param_1[0x2a7] = '\0';
    }
    if (DAT_00a1b120 == local_84) {
      *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0x2c);
      *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 0x28);
      *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x4c);
      *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_1 + 0x58);
    }
    if ((local_84 < DAT_00a1b120) && ((DAT_00a1b120 - local_84) % local_88 == 0)) {
      *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0x2c);
      *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 0x28);
      *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x4c);
      *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_1 + 0x58);
    }
    DAT_00a1b118 = *(int *)(param_1 + 0x28);
    DAT_00a1b11f = param_1[3];
    DAT_00a1b11e = param_1[4];
    DAT_00a1b11d = param_1[5];
    DAT_00a1b11c = param_1[6];
    if (bVar5) {
      param_1[0x74] = '\x01' - (param_1[0xdc] != '\x01');
      param_1[0x76] = '\x01' - (param_1[0xdd] != '\x01');
      param_1[0x78] = '\x01' - (param_1[0xde] != '\x01');
      param_1[0x7a] = '\x01' - (param_1[0xdf] != '\x01');
      param_1[0x7c] = '\x01' - (param_1[0xe0] != '\x01');
      param_1[0x7e] = '\x01' - (param_1[0xe1] != '\x01');
      param_1[0x82] = '\x01' - (param_1[0xe2] != '\x01');
      param_1[0x80] = '\x01' - (param_1[0xe3] != '\x01');
      param_1[0x84] = '\x01' - (param_1[0xe4] != '\x01');
      param_1[0x87] = '\x01' - (param_1[0xf7] != '\x01');
      param_1[0x89] = '\x01' - (param_1[0xf8] != '\x01');
    }
    else {
      param_1[0x89] = '\0';
      param_1[0x87] = '\0';
      param_1[0x84] = '\0';
      param_1[0x80] = '\0';
      param_1[0x82] = '\0';
      param_1[0x7a] = '\0';
      param_1[0x78] = '\0';
      param_1[0x76] = '\0';
      param_1[0x74] = '\0';
    }
    if ((DAT_00a1b116 == '\0') && (param_1[0x74] != '\0')) {
      local_8c = '\x01';
    }
    else {
      local_8c = '\0';
    }
    param_1[0x75] = local_8c;
    DAT_00a1b116 = param_1[0x74];
    if ((DAT_00a1b115 == '\0') && (param_1[0x76] != '\0')) {
      local_90 = '\x01';
    }
    else {
      local_90 = '\0';
    }
    param_1[0x77] = local_90;
    DAT_00a1b115 = param_1[0x76];
    if ((DAT_00a1b114 == '\0') && (param_1[0x78] != '\0')) {
      local_94 = '\x01';
    }
    else {
      local_94 = '\0';
    }
    param_1[0x79] = local_94;
    DAT_00a1b114 = param_1[0x78];
    if ((DAT_00a1b113 == '\0') && (param_1[0x7a] != '\0')) {
      local_98 = '\x01';
    }
    else {
      local_98 = '\0';
    }
    param_1[0x7b] = local_98;
    DAT_00a1b113 = param_1[0x7a];
    if ((DAT_00a1b112 == '\0') && (param_1[0x7c] != '\0')) {
      local_9c = '\x01';
    }
    else {
      local_9c = '\0';
    }
    param_1[0x7d] = local_9c;
    DAT_00a1b112 = param_1[0x7c];
    if ((DAT_00a1b111 == '\0') && (param_1[0x7e] != '\0')) {
      local_a0 = '\x01';
    }
    else {
      local_a0 = '\0';
    }
    param_1[0x7f] = local_a0;
    DAT_00a1b111 = param_1[0x7e];
    if ((DAT_00a1b110 == '\0') && (param_1[0x82] != '\0')) {
      local_a4 = '\x01';
    }
    else {
      local_a4 = '\0';
    }
    param_1[0x83] = local_a4;
    DAT_00a1b110 = param_1[0x82];
    if ((DAT_00a1b10f == '\0') && (param_1[0x80] != '\0')) {
      local_a8 = '\x01';
    }
    else {
      local_a8 = '\0';
    }
    param_1[0x81] = local_a8;
    DAT_00a1b10f = param_1[0x80];
    if ((DAT_00a1b10e == '\0') && (param_1[0x84] != '\0')) {
      local_ac = '\x01';
    }
    else {
      local_ac = '\0';
    }
    param_1[0x85] = local_ac;
    if ((DAT_00a1b10e == '\0') || (param_1[0x84] != '\0')) {
      local_b0 = '\0';
    }
    else {
      local_b0 = '\x01';
    }
    param_1[0x86] = local_b0;
    DAT_00a1b10e = param_1[0x84];
    if ((DAT_00a1b10d == '\0') && (param_1[0x87] != '\0')) {
      local_b4 = '\x01';
    }
    else {
      local_b4 = '\0';
    }
    param_1[0x88] = local_b4;
    DAT_00a1b10d = param_1[0x87];
    if ((DAT_00a1b10c == '\0') && (param_1[0x89] != '\0')) {
      local_b8 = '\x01';
    }
    else {
      local_b8 = '\0';
    }
    param_1[0x8a] = local_b8;
    DAT_00a1b10c = param_1[0x89];
    FUN_0042e830();
  }
  return;
}

