# Plant Setup witin Home Assistant

## homeassistant-plant

Alternative plants component for Home Assistant (Version 2)
This integration can automatically fetch data from OpenPlantBook if you are a registered user. Registration is free.

Plants are set up in the UI and all configuration of your plants can be managed there or by automations and scripts.

Plants are now treated as devices in Version 2
This means that the main plant entity references other entities, and they are grouped togheter in the GUI as a single device.

## Installation

### OpenPlantbook

This appears to go pretty well but some of the docs appear out of date.

Install and set up [OpenPlantbook](https://github.com/Olen/home-assistant-openplantbook) (Not required, but strongly recommended)

Set it up, and add your client_id and secret, and test it by using e.g. the openplantbook.search service call to search for something.
The search seems to work.
openplantbook.get failes but mayeb I do not unserstand what goes in the field. Tried: (What was returned from search)

- Persicaria odorata
- Petroselinum crispum

``` bash
This error originated from a custom integration.

Logger: pyopenplantbook
Source: custom_components/openplantbook/__init__.py:87
integration: OpenPlantbook (documentation, issues)
First occurred: 07:07:15 (3 occurrences)
Last logged: 07:09:15

404, message='Not Found', url=URL('https://open.plantbook.io/api/v1/plant/detail/Petroselinum%20crispum/')
404, message='Not Found', url=URL('https://open.plantbook.io/api/v1/plant/detail/petroselinum%20crispum:%20Petroselinum%20crispum/')
404, message='Not Found', url=URL('https://open.plantbook.io/api/v1/plant/detail/parsley/')
```

No results returned.

#### openplantbook.clean_cache error

Failed to call service openplantbook.clean_cache. Unknown error

### Install new flower-card for Lovelace

[new flower-card for Lovelace](https://github.com/Olen/lovelace-flower-card/)

Currently this is the only card in lovelace that support this integration. Feel free to fork and update - or create PRs - for other lovelace cards.

I see no errors or warnings when restarted.

So how would I install a plant "device" from openplantbook?

How would I add a plant "device"?

## Errors

When I try to add a "plat" device, 

This device cannot be added from the UI
You can add this device by adding it to your 'configuration.yaml'. See the documentation for more information.

