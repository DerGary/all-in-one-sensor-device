#!/bin/bash
md-to-pdf ./Instructions.md --pdf-options '{"format": "A4", "margin":"15mm", "outline":true}' --launch-options '{ "args": ["--no-sandbox"] }'